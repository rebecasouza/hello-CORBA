import sys
from omniORB import CORBA
import CosNaming
import HelloApp


orb = CORBA.ORB_init()

obj = orb.string_to_object("corbaname::localhost:1050/NameService#hello")
hello = obj._narrow(HelloApp.Hello)

if hello is None:
    print("Can't narrow reference")
    sys.exit(1)

print(hello.sayHello())
