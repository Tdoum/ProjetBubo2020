CXX=g++
CXXFLAGS=-std=c++14 -I /usr/local/include/Poco/ -L /usr/local/lib -lPocoFoundation -lPocoNet -lPocoNetSSL -lPocoUtil -lPocoXML -lpthread
LDFLAGS=
LLIB=lib/
LDEFS=
SOURCES=
SOURCESSERIAL=../serialib/

all: lib
	$(CXX) Tubdd.cpp $(LLIB)Mail.o $(LLIB)Internet.o $(LLIB)Config.o $(LLIB)Enregistrement.o $(LLIB)Logger.o $(LLIB)Horodatage.o $(LLIB)Lampadaire.o $(LLIB)Ampoule.o $(LLIB)Galerie.o $(LLIB)GPS.o $(LLIB)Geolocalisation.o $(LLIB)serialib.o  $(LLIB)BDD.o $(LLIB)Collecteur.o $(LLIB)Luxmetre.o -lsqlite3 -lcgicc -W -Wall -ansi $(CXXFLAGS) -o Tubdd

	
lib: $(LLIB)Enregistrement.o $(LLIB)Logger.o $(LLIB)Mail.o $(LLIB)Internet.o $(LLIB)Config.o  $(LLIB)Horodatage.o  $(LLIB)Lampadaire.o  $(LLIB)Ampoule.o  $(LLIB)Galerie.o  $(LLIB)GPS.o  $(LLIB)Geolocalisation.o  $(LLIB)serialib.o $(LLIB)BDD.o  $(LLIB)Collecteur.o  $(LLIB)Luxmetre.o



$(LLIB)Enregistrement.o: $(SOURCES)Enregistrement.cpp  $(LDEFS)Enregistrement.h
	$(CXX) -c $(SOURCES)Enregistrement.cpp -o $@ $(CXXFLAGS)

$(LLIB)Mail.o: $(SOURCES)Mail.cpp  $(LDEFS)Mail.h
	$(CXX) -c $(SOURCES)Mail.cpp -o $@ $(CXXFLAGS)

$(LLIB)Internet.o: $(SOURCES)Internet.cpp  $(LDEFS)Internet.h
	$(CXX) -c $(SOURCES)Internet.cpp -o $@ $(CXXFLAGS)

$(LLIB)Config.o: $(SOURCES)Config.cpp  $(LDEFS)Config.h
	$(CXX) -c $(SOURCES)Config.cpp -o $@ $(CXXFLAGS)

$(LLIB)serialib.o: $(SOURCESSERIAL)serialib.cpp  $(SOURCESSERIAL)serialib.h
	$(CXX) -c $(SOURCESSERIAL)serialib.cpp -o $@ $(CXXFLAGS)

$(LLIB)Logger.o: $(SOURCES)Logger.cpp  $(LDEFS)Logger.h
	$(CXX) -c $(SOURCES)Logger.cpp -o $@ $(CXXFLAGS)

$(LLIB)Horodatage.o: $(SOURCES)Horodatage.cpp	 $(LDEFS)Horodatage.h
	$(CXX) -c $(SOURCES)Horodatage.cpp -o $@ $(CXXFLAGS)

$(LLIB)Lampadaire.o: $(SOURCES)Lampadaire.cpp   $(LDEFS)Lampadaire.h
	$(CXX) -c $(SOURCES)Lampadaire.cpp -o $@ $(CXXFLAGS)

$(LLIB)Ampoule.o: $(SOURCES)Ampoule.cpp  $(LDEFS)Ampoule.h
	$(CXX) -c $(SOURCES)Ampoule.cpp -o $@ $(CXXFLAGS)

$(LLIB)Galerie.o: $(SOURCES)Galerie.cpp  $(LDEFS)Galerie.h
	$(CXX) -c $(SOURCES)Galerie.cpp -o $@ $(CXXFLAGS)

$(LLIB)GPS.o: $(SOURCES)GPS.cpp  $(LDEFS)GPS.h
	$(CXX) -c $(SOURCES)GPS.cpp -o $@ $(CXXFLAGS)

$(LLIB)Geolocalisation.o: $(SOURCES)Geolocalisation.cpp  $(LDEFS)Geolocalisation.h
	$(CXX) -c $(SOURCES)Geolocalisation.cpp -o $@ $(CXXFLAGS)

$(LLIB)BDD.o: $(SOURCES)BDD.cpp  $(LDEFS)BDD.h
	$(CXX) -c $(SOURCES)BDD.cpp -o $@ $(CXXFLAGS)

$(LLIB)Luxmetre.o: $(SOURCES)Luxmetre.cpp  $(LDEFS)Luxmetre.h
	$(CXX) -c $(SOURCES)Luxmetre.cpp -o $@ $(CXXFLAGS)

$(LLIB)Collecteur.o: $(SOURCES)Collecteur.cpp  $(LDEFS)Collecteur.h
	$(CXX) -c $(SOURCES)Collecteur.cpp -o $@ $(CXXFLAGS)





clean:
	rm -rf *.o
mrproper:
	clean rm -rf Tubdd
