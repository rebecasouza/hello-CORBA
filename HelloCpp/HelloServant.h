#ifndef __HELLO_SERVANT_H__
#define __HELLO_SERVANT_H__

#include "Hello.hh" // Class' header file

class HelloServant : public POA_HelloApp::Hello
{
	public:
		inline HelloServant() {}
  	virtual ~HelloServant() {}
		virtual char * sayHello();
};

#endif // __HELLO_SERVANT_H__
