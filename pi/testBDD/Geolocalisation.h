#ifndef DEF_GEOLOCALISATION
#define DEF_GEOLOCALISATION

#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <array>
#include <algorithm>
#include "GPS.h"

class Geolocalisation
{
	private :
		GPS *leGPS;
		char longitude [10];
		char latitude[10];
		char altitude[10];
	public :
		Geolocalisation(GPS *unGPS);
		Geolocalisation();
		int localiser(char latitude[10], char longitude[10]);
		int localiserSF(char latitude[10], char longitude[10]);
		void getLongitude(char longitude [10]);
		void getLatitude(char latitude[10]);
		void setLongitude(char aLongitude[10]);
		void setLatitude(char aLatitude[10]);
	private :
		int extraireLatitudeRMC(std::vector<char> trameRMC, double &latitude);
		int extraireLongitudeRMC(std::vector<char> trameRMC, double &longitude);
		int extraireAltitude(std::vector<char> trameGPGGA, double &altidtude);
		int filtrage (std::array <std::vector<double>,2> lotCoordonnees, double &latitude, double &longitude);

};

#endif