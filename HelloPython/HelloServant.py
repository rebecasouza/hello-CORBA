import HelloApp, HelloApp__POA

class HelloServant (HelloApp__POA.Hello):
    def sayHello(self):
        return "Hello from Python Server!!!"
