#ifndef DEF_GEOLOCALISATION
#define DEF_GEOLOCALISATION

#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "GPS.h"

class Geolocalisation
{
	private :
		GPS *leGPS;
		char longitude [10];
		char latitude[10];
	public :
		Geolocalisation(GPS *unGPS);
		Geolocalisation();
		int localiser(char latitude[10], char longitude[10]);
		public: void getLongitude(char longitude [10]);
		public: void getLatitude(char latitude[10]);
	private :
		int extraireLatitudeRMC(std::vector<char> trameRMC, double &latitude);
		int extraireLongitudeRMC(std::vector<char> trameRMC, double &longitude);

		public: void setLongitude(char aLongitude[10]);

		public: void setLatitude(char aLatitude[10]);

};

#endif