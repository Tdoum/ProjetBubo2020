
CXX=g++
CXXFLAGS=-std=c++11 -lPocoFoundation -lPocoNet -lPocoNetSSL -lPocoUtil -lPocoXML -O2 -I/usr/local/include/Poco
LDFLAGS=
LLIB=lib/
LDEFS=
SOURCES=


all: lib
	$(CXX) TIenvoimail.cpp.cpp $(LLIB)Internet.cpp $(LLIB)Mail.cpp $(LLIB)Config.cpp  			-lPocoFoundation -lPocoNet -lPocoNetSSL -lPocoUtil -lPocoXML -W -Wall -ansi 			$(CXXFLAGS) -o TIenvoimail



clean:
	rm -rf *.o
