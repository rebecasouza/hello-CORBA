#include <iostream>
#include <string>
#include <omniORB4/CORBA.h>
#include <omniORB4/Naming.hh>
#include "Hello.hh"

using namespace std;

int main(int argc, char** argv) {

  // Declare ORB
  CORBA::ORB_var orb;

  CORBA::Object_var obj;

  try {
    // Initialize the ORB
    orb = CORBA::ORB_init(argc, argv);

    try {
      obj= orb->string_to_object("corbaname::localhost:1050/NameService#hello");
    } catch (const CORBA::Exception &) {
      cerr << "Bad format for stringified reference" << endl;
      exit(1);
    }

    HelloApp::Hello_var hello = HelloApp::Hello::_narrow(obj);

    // Check that reference is non-nil
    if (CORBA::is_nil(hello)) {
      cerr << "Can't narrow reference" << endl;
      exit(1);
    }

    cout << hello->sayHello() << endl;

    orb->destroy();
  } catch (CORBA::UNKNOWN) {
		cerr << "Caught CORBA exception: unknown exception" << endl;
    exit(1);
	} catch (CORBA::SystemException &) {
		cerr << "Caught CORBA exception: system exception" << endl;
    exit(1);
	}
}
