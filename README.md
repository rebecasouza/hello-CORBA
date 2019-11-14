# hello-CORBA
A distributed client-server "Hello World" implementation in different languages  using CORBA

These examples were created with the following dependencies:  

Java - from 1.6 to 1.8  
Python - 2.7  
omniORB - 4.2.3  
Maven - 3.6.2  
make  

###### Run tnameserv:  

```console  
$ orbd -ORBInitialPort 1050 -ORBDInitialHost localhost  
```  
For running the project in different machines, replace every instance of "localhost" with the server host's IP address  

## JAVA

Compile the source code  
If you don't have any Java IDE installed make sure to have maven and use the terminal to compile the code  
From HelloJava directory on the terminal run:  
```console  
$ mvn clean package  
```
###### Run Java Server  

From HelloJava directory on the terminal run:  
```console  
$ java HelloApp.HelloServer  
```  
if you have any issues regarding classpath as "Could not find or load main class..." try  
```console  
$ java -cp target/HelloJava-1.0-SNAPSHOT.jar HelloApp.HelloServer  
```
###### Run Java Client  

From HelloJava directory on the command line  
```console  
$ java HelloApp.HelloClient  
```  
if you have any issues regarding classpath as "Could not find or load main class..." try  
```console  
$ java -cp target/HelloJava-1.0-SNAPSHOT.jar HelloApp.HelloClient  
```

## PYTHON  

###### Run Python Server  

From HelloPython directory on the terminal run:  
```console  
$ python2 HelloServer.py  
```  
###### Run Python Client  
```console  
$ python2 HelloClient.py  
```  

## C++  

Compile the source code  
From HelloCpp directory on the terminal run:  
```console  
$ make  
```  
###### Run C++ Client  
```console  
$ ./client  
```  

You can run server and client in any language interchangeably  

## Resources:  

https://docs.oracle.com/javase/7/docs/technotes/guides/idl/INStutorial.html
http://www.upi.pr.it/docs/jagsa/jaggsntp14.htm
https://whatis.techtarget.com/definition/IIOP-Internet-Inter-ORB-Protocol
http://omniorb.sourceforge.net/omni42/omniORB.pdf
http://omniorb.sourceforge.net/omnipy42/omniORBpy/omniORBpy002.html
http://omniorb.sourceforge.net/omnipy3/omniORBpy/omniORBpy006.html
http://www.bioinformatics.org/bradstuff/bc/IntroPythonServer.pdf
http://www.ing.iac.es/~docs/external/python/omniOrb/omniORBpy.pdf
http://code.activestate.com/recipes/81254-implement-a-corba-client-and-server/
https://fossies.org/linux/omniORB/doc/omniORB/omniORB.html
http://omniorb.sourceforge.net/omnipy42/omniORBpy/omniORBpy002.html#text5
https://objectcomputing.com/resources/publications/sett/january-2002-corba-and-java-by-don-busch-principal-software-engineer
http://omniorb.sourceforge.net/omnipy3/omniORBpy/omniORBpy006.html
https://github.com/aayvazyan-tgm/CORBA
https://www.codeproject.com/Articles/24863/A-Simple-C-Client-Server-in-CORBA
http://omniorb.sourceforge.net/omni40/omniORB/omniORB002.html
https://books.google.com.br/books?id=AZgnDwAAQBAJ&pg=PT288&lpg=PT288&dq=using+corbaname+java&source=bl&ots=CBUm1tPpky&sig=ACfU3U2uqMO9KluQnx6z12R4e-mCxxqk_Q&hl=en&sa=X&ved=2ahUKEwiwr-GboNblAhUAHbkGHWNJCNEQ6AEwBXoECAkQAQ#v=onepage&q=using%20corbaname%20java&f=false
https://docs.oracle.com/cd/E13211_01/wle/cref/index.htm
http://www.dca.fee.unicamp.br/projects/sapiens/Resources/corba/corba.html
https://www.ime.usp.br/~reverbel/SMW-07/Material/orbix_6.3_pguide_java.pdf
