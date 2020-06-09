#ifndef DEF_GEOLOCALISATION
#define DEF_GEOLOCALISATION

#include <iostream>
#include <iomanip>
#include <sstream> 
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>

#include "GPS.h"

#define PBFIX -1
#define OK 1

class Geolocalisation
{
        private :
			GPS *leGPS;
			
			char longitude[15];
			char latitude[15];
			char altitude[4];
			char nord;
			char est;
			char fix;
			char satellite[3];
			int intSatellite,nbrIterations;
			char HDOP[5];
			bool vCond;
			//char trouverLongitude();
			void calculLongitude(string leChamps[200]);
			void calculLatitude(string leChamps[200]);
			void calculAltitude(string leChamps[200]);
			void calculSatellite(string leChamps[200]);
			char calculNord(string leChamps[200]);
			char calculEst(string leChamps[200]);
			char calculFixe(string leChamps[200]);
			char calculHDOP(string leChamps[200]);
			float calculAltitude();
			int chronometer();
			thread activerChrono();

		public : 		
				
			Geolocalisation(GPS *unGPS);
			Geolocalisation();

			int localiser();
			void getLongitude(char longitude[12]);
			void getLatitude(char alatitude[12]);
			void getAltitude(char aaltitude[4]); 
			void getSatellite(char asatellite[3]);
			void getHDOP(char aHDOP[5]);
			char getFIX();
			int getNbreAcquisition();

			void setLongitude(char aLongitude[12]);
			void setLatitude(char aLatitude[12]);
			void setAltitude(char aaltitude[4]);

			void setVCond(bool vCond);

			
};		
#endif