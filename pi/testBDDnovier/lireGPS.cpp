#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "Geolocalisation.h"
#include "Collecteur.h"
#include "Enregistrement.h"
#include "Logger.h"
#include "Lampadaire.h"
#include "Galerie.h"
#include "Ampoule.h"
#include "Horodatage.h"
#include "GPS.h"
#include "Logger.h"

using namespace std;
using namespace cgicc;
int main(){

	  Collecteur *leCollecteur= new Collecteur();
	  leCollecteur->creerEnregistrementVirtuel();
	  cout <<HTTPHTMLHeader();
	  string geolocalisation = leCollecteur->geolocaliser();
	  cout<<geolocalisation;
	  leCollecteur->supprimerEnregistrementVirtuel();
	//GPS *legps=new GPS();
	//Enregistrement * unEnregistrement = new Enregistrement(legps);
	//char laDate[6];
	//char latitude[10] ;
 //   char longitude[10] ;
	//cout<<"localiser " <<endl;
	//int erreur = unEnregistrement->localiser();
	//cout<<"localiser erreur " <<erreur<<endl;
	//switch (erreur)
 //       {
 //               case MAUVAISETRAME : cout<<"MAUVAISE TRAME "<< " error" <<endl;
 //                       break;          
 //               case ALERTE : cout<<"ALERTE GPS non pr�t  "<< " error" <<endl;
 //                       this_thread::sleep_for (chrono::seconds(1));
 //                       break;          
 //               case ERREURCHECKSUM : cout<< "ERREUR DE CHECKSUM "<< " error"<<endl;
 //                       break;
 //               case ECHECCAPTURE : cout<<"ECHEC CAPTURE "<< " error" <<endl;
 //                       break;
 //               case ERREURACCESPORT : cout<<"ERREUR ACCES PORT "<< " error" <<endl;
 //                       break;
 //               default : 
	//				unEnregistrement->getGeolocalisation( latitude, longitude);
	//				cout<<"{\n\t\"LATITUDE\":"<<latitude<<",\n";
	//				cout<<"\t\"LONGITUDE\":"<<longitude<<",\n";
	//				//-------------------------------------------------------//
	//				unEnregistrement->getHorodatage(laDate);
	//				cout<<"\t\"DATE\":"<<laDate<<"\n}\n";


	//				/*	for (int i=0;i<6;i++)
	//					{
	//					heure[i];
	//					}
	//					cout<<"\t\"HEURE\":"<<heure<<"\n}\n"; */
	//				//-----------------------------------------------------//
 //                     break;
 //       }
    return 0;
}