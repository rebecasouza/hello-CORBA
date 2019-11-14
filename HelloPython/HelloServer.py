import sys
from omniORB import CORBA
import CosNaming, PortableServer
from HelloServant import HelloServant

sys.argv.extend(("-ORBInitRef", "NameService=corbaname::localhost:1050"))

# Initialize the ORB and the POA
orb = CORBA.ORB_init(sys.argv, CORBA.ORB_ID)
poa = orb.resolve_initial_references("RootPOA")

# create servant and register it with the POA
hello = HelloServant()
servantId = poa.activate_object(hello);

# Publish the hello object reference to the Naming Service
ref = poa.id_to_reference(servantId)

# Get the Naming Service's root naming context
obj = orb.resolve_initial_references("NameService")
rootContext = obj._narrow(CosNaming.NamingContext)


if rootContext is None:
	print("Failed to narrow the root naming context")
	sys.exit(1)

# Create a new context naming
# path = [CosNaming.NameComponent("some context", "")]

# Bind the the new context to the root context
# try:
#     context = rootContext.bind_new_context(path)
#     print("New hello context bound to the Naming Service")
#
# except CosNaming.NamingContext.AlreadyBound, ex:
#     obj = rootContext.resolve(path)
#     context = obj._narrow(CosNaming.NamingContext)
#
#     if context is None:
#         print("Context exists but is not a NamingContext")
#         sys.exit(1)

text = "hello"
path = [CosNaming.NameComponent("hello", "")]

try:
    # context.bind(path, ref)
    rootContext.bind(path, ref)
    print("Bound the hello object to the naming service")

except CosNaming.NamingContext.AlreadyBound, ex:
    print("Hello object already bound, rebinding new object")
    # context.rebind(path, ref)
    rootContext.rebind(path, ref)

# Activate the POA Manager and run
poa._get_the_POAManager().activate()
print("Python Server active and waiting...")
orb.run()
