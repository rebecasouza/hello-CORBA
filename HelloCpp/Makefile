# Makefile

OMNIORB_HOME=/usr/local/Cellar/omniorb/4.2.3

IDL=$(OMNIORB_HOME)/bin/omniidl
IDLFLAGS=-bcxx

INCLUDES=-I$(OMNIORB_HOME)/include -I$(OMNIORB_HOME)/include/omniORB4

LIBS=-L$(OMNIORB_HOME)/lib -lomnithread -lomniORB4

IDL_FILE = Hello.idl

.PHONY: all
all: HelloServer HelloClient

HelloServer: HelloServer.o HelloServant.o HelloSK.o
	$(CXX) -o $@ $^ $(LIBS)

HelloServer.o: HelloServer.cpp HelloServant.h

HelloClient: HelloClient.o HelloSK.o
	$(CXX) -o $@ $^ $(LIBS)

HelloClient.o: HelloClient.cpp HelloSK.cc

HelloServant.h: Hello.hh

HelloServant.o: HelloServant.cpp HelloServant.h Hello.hh

HelloSK.o: HelloSK.cc Hello.hh

HelloSK.cc Hello.hh: $(IDL_FILE)
	$(IDL) $(IDLFLAGS) $<

.PHONY: clean
clean:

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES)

.cc.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(INCLUDES)
