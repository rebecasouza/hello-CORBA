#include "HelloServant.h"
#include <iostream>
#include <omniORB4/CORBA.h>
#include <omniORB4/Naming.hh>

/** Server name, clients needs to know this name */
// #define SERVER_NAME		"MyServerName"

using namespace std;

int main(int argc, char ** argv)
{
	try {

		//------------------------------------------------------------------------
		// Initialize CORBA ORB
		//------------------------------------------------------------------------
		CORBA::ORB_ptr orb = CORBA::ORB_init(argc, argv);

		//------------------------------------------------------------------------
		// Initialize POA: Get reference to root POA
		//e
		// Servant must register with POA in order to be made available for client
		// Get reference to the RootPOA.
		//-----------------------------------------------------------------------
		CORBA::Object_var poa_obj = orb->resolve_initial_references("RootPOA");
		PortableServer::POA_var poa = PortableServer::POA::_narrow(poa_obj);
		PortableServer::POAManager_var manager = poa->the_POAManager();

		//------------------------------------------------------------------------
		// Create service
		//------------------------------------------------------------------------
		HelloServant * hello = new HelloServant;

		try {
			//------------------------------------------------------------------------
			// Bind object to name service as defined by directive InitRef
			// and identifier "NameService" in config file omniORB.cfg.
			//------------------------------------------------------------------------
			CORBA::Object_var ns_obj = orb->resolve_initial_references("NameService");
			if (!CORBA::is_nil(ns_obj)) {
				//------------------------------------------------------------------------
				// Narrow this to the naming context
				//------------------------------------------------------------------------
				CosNaming::NamingContext_ptr nc = CosNaming::NamingContext::_narrow(ns_obj);

				//------------------------------------------------------------------------
				// Bind to CORBA name service. Same name to be requested by client.
				//------------------------------------------------------------------------
				CosNaming::Name name;
				name.length(1);
				// name[0].id = CORBA::string_dup(SERVER_NAME);
				name[0].id = CORBA::string_dup("");
				name[0].kind = CORBA::string_dup("hello");
				nc->rebind(name, hello->_this());

				//------------------------------------------------------------------------
				// Intizialization ready, server runs
				//------------------------------------------------------------------------
				cout << argv[0] << " C++ server is running .." << endl;
			}
		} catch (CosNaming::NamingContext::NotFound &) {
			cerr << "Caught CORBA exception: not found" << endl;
			exit(1);
		} catch (CosNaming::NamingContext::InvalidName &) {
			cerr << "Caught CORBA exception: invalid name" << endl;
			exit(1);
		} catch (CosNaming::NamingContext::CannotProceed &) {
			cerr << "Caught CORBA exception: cannot proceed" << endl;
			exit(1);
		}

		//------------------------------------------------------------------------
		// Activate the POA manager
		//------------------------------------------------------------------------
		manager->activate();

		//------------------------------------------------------------------------
		// Accept requests from clients
		//------------------------------------------------------------------------
		orb->run();

		//------------------------------------------------------------------------
		// Clean up
		//------------------------------------------------------------------------
		delete hello;

		//------------------------------------------------------------------------
		// Destroy ORB
		//------------------------------------------------------------------------
		orb->destroy();

	} catch (CORBA::UNKNOWN) {
		cerr << "Caught CORBA exception: unknown exception" << endl;
	} catch (CORBA::SystemException &) {
		cerr << "Caught CORBA exception: system exception" << endl;
	}
}
