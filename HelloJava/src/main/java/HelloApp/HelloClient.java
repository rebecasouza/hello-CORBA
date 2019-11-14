package HelloApp;

import java.util.Properties;
import org.omg.CosNaming.NamingContextPackage.CannotProceed;
import org.omg.CosNaming.NamingContextPackage.InvalidName;

public class HelloClient {

  public static void main(String[] args) {

    org.omg.CORBA.ORB orb = org.omg.CORBA.ORB.init(args, null);

    // Finds the object "hello" corba object associated with the servant previously attached to the naming Service
    org.omg.CORBA.Object obj = orb.string_to_object("corbaname::localhost:1050#hello");

    Hello hello = HelloHelper.narrow(obj);

    try {
      System.out.println(hello.sayHello());
    } catch (org.omg.CORBA.SystemException e) {
      System.out.println("There was a problem with the client...\n" + e.getMessage());
    }

  }
}
