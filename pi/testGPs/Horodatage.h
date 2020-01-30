#ifndef DEF_HORODATAGE
#define DEF_HORODATAGE

#include <vector>
#include <algorithm>
#include "GPS.h"

class Horodatage
{

			GPS *leGPS ;
			char date [6];
			char heure [6];
		public :
			Horodatage(GPS *unGPS);
			Horodatage();
			int dater();
		private :
			int extraireDateRMC(std::vector<char>trameRMC, char date[6] );
			int extraireHeureRMC(std::vector<char>trameRMC, char heure [6]);
		public: void setDate(char aDate[6]);

		public: void getDate(char aDate[6]);

};

#endif
