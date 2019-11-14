package HelloApp;

import java.util.Properties;

public class HelloServer {

  public static void main(String[] args) {

    Properties prop = new Properties();
    prop.put("org.omg.CORBA.ORBInitialHost", "localhost");
    prop.put("org.omg.CORBA.ORBInitialPort", "1050");

    // Create and initialize the ORB and the POA
    org.omg.CORBA.ORB orb = org.omg.CORBA.ORB.init(args, prop);
    // Instantiate a CORBA object and a POA Manager
    org.omg.CORBA.Object obj = null;
    org.omg.PortableServer.POA rootPOA = null;

    try {
      // Get object reference associated with RootPOA service
      obj = orb.resolve_initial_references("RootPOA");
    } catch (org.omg.CORBA.ORBPackage.InvalidName e){
      System.out.println("No service with name: " + e.getMessage());
    }

    // Pass object reference to the POA Manager
    rootPOA = org.omg.PortableServer.POAHelper.narrow(obj);
    // Create a servant instance
    HelloServant hello = new HelloServant();
    // Create a naming service
    org.omg.CosNaming.NamingContextExt rootContext = null;

    try {
      // Retister the servant with the POA
      byte[] servantId = rootPOA.activate_object(hello);
      // Publish the hello object reference to the Naming Service
      org.omg.CORBA.Object ref = rootPOA.id_to_reference(servantId);
      org.omg.CORBA.Object objRef = null;

      try {
        // Get the naming service's root naming context
        objRef = orb.resolve_initial_references("NameService");
        System.out.println("Finding naming service...");
        rootContext = org.omg.CosNaming.NamingContextExtHelper.narrow(objRef);
        System.out.println("Naming Service Found!!!");
      } catch (org.omg.CORBA.ORBPackage.InvalidName name) {
        System.out.println("Invalid service name...");
        name.printStackTrace();
        System.exit(0);
      }
      // Create a new naming reference and add it to the context
      String text = "hello";
      org.omg.CosNaming.NameComponent[] path = rootContext.to_name(text);
      try {
        // Bins the new naming reference to the object
        rootContext.bind(path, ref);
      } catch (org.omg.CosNaming.NamingContextPackage.NotFound e) {
        System.out.println("Object not found...");
        System.exit(0);
      } catch (org.omg.CosNaming.NamingContextPackage.AlreadyBound e) {
        System.out.println("Object already exists...");
        rootContext.rebind(path, ref);
        System.out.println("Rebinding object...");
      } catch (org.omg.CosNaming.NamingContextPackage.CannotProceed e) {
        System.out.println("Error. Server cannot proceed...");
        System.exit(0);
      }

      // Activate the POA Manager and run
      rootPOA.the_POAManager().activate();
      System.out.println("Java Server active and waiting...");
      orb.run();

    } catch (java.lang.Exception e) {
      System.out.println("There was a problem with the server...\n" + e.getMessage());
    }
  }
}
