#include "HelloServant.h"
#include <iostream>

using namespace std;

char* HelloServant::sayHello()
{
  return CORBA::string_dup("Hello from C++ Server!!!");
}
