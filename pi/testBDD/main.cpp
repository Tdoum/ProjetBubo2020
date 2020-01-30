#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include <string>

#include <stdio.h>


#include "Geolocalisation.h"
#include "Collecteur.h"
#include "BDD.h"
#include "Enregistrement.h"
#include "Logger.h"
#include "Lampadaire.h"
#include "Galerie.h"
#include "Ampoule.h"
#include "Horodatage.h"
#include "GPS.h"

using namespace std;
using namespace cgicc;


int main(){
float aAlbedo=0.6;
float aFluxLum=20.0;
string aTypeAmpoule="LED";
string aTypeLampadaire="Poto";
int aHauteur=4;
double aLatitude=1.55555555;
double aLongitude=1.66666666;
int aNbImages=0;
string aAgglo="tlse";
string aRue="perd";
int aUlor=5;
string aDate="188888";
string aNotes="Bonjour";
int puissance=10;
string aIdEnregistrement="205566331144";
string aIdRaspberry="000000000";
int aId=20;


float albedo=0.6;
float fluxLum=20.0;
string typeAmpoule="LED";
string typeLampadaire="Poto";
int hauteur=4;
double latitude=1.55555;
double longitude=1.66666666;
int nbImages=0;
string agglo="tlse";
string rue="perd";
int ulor=5;
string date="130318";
string notes="Bonjour les amis";
//int puissance=10;
string idEnregistrement="205566331155";
string idRaspberry="111111111";
int id=5;

	Enregistrement * unEnregistrement = new Enregistrement( aAlbedo,  aFluxLum,  aIdEnregistrement,  aIdRaspberry,  aTypeAmpoule, aTypeLampadaire,  aHauteur,  aLatitude,  aLongitude,  aNbImages,  aAgglo, aRue,  aUlor,  aDate,  aNotes,  puissance) ;

	GPS legps;

	Collecteur leCollecteur;


	leCollecteur.recupererIdentifiantRaspberry();

	char laDate[6];

	BDD laBDD;


//	char latitude[10];
//	char longitude[10];

	cout<<"Collecteur test"<<endl;
	laBDD.sauvegarderDonneesEnregistrement(unEnregistrement,aIdRaspberry);
	cout<<"Bonjour"<<endl;//test a l'execution
	cout<< "?????????????????"<<endl;
	cout<<"au revoir"<<endl;// re_test
	//cout << "Content-type:text/json\r\n\r\n";
	//cout <<endl;
	cout<< "?????????????????"<<endl;
	cout<< "?????????????????"<<endl;
	cout<<"test Collecteur"<<endl;
        

    laBDD.modifierEnregistrement(id,puissance,albedo,fluxLum,idEnregistrement,idRaspberry,typeAmpoule,typeLampadaire,hauteur,latitude,longitude,nbImages,agglo,rue,ulor,date,notes);
cout<<"test de l'execution"<<endl;
	return 0;

}



int Collecteur::recupererIdentifiantRaspberry() {

	FILE * pFile;
    char buffer[1200]; 
    size_t result=0, posSerial=0;
	string match;

	pFile =fopen("/proc/cpuinfo", "r");
	if (pFile==NULL) {
		return PBACCESIDENT;
	}


    result = fread (buffer, 1, sizeof (buffer),pFile);
    if (result <=0 ) {
		return PBLECTUREIDENT;
	}

	buffer[result] == '\0';

	match=string(buffer);
	posSerial = match.find("Serial");

	_identifiant = match.substr(posSerial + 10,16);

	fclose (pFile);
	return 1;
}



string Collecteur::getIdentifiant()
{
	return _identifiant;
}

Collecteur::Collecteur()
{
	unGPS=new GPS();
}
string Collecteur::creerEnregistrement()
{
	this->listeEnregistrements.push_back(new Enregistrement(unGPS));
	if (!listeEnregistrements.empty()) {
		listeEnregistrements.back()->creerIdentifiant();
	}
}



string Collecteur::geolocaliser()
{
	char laLatitude[10];
	char laLongitude[10];
	int erreur=0;
	string retour;
	if (!listeEnregistrements.empty()) {
		erreur = listeEnregistrements.back()->localiser(laLatitude, laLongitude);
	}
    switch (erreur)
	{
		case MAUVAISETRAME : retour ="MAUVAISE TRAME ";
			break;
		case ALERTE : retour ="ALERTE GPS non pr�t  ";
			break;
		case ERREURCHECKSUM : retour ="ERREUR DE CHECKSUM ";
			break;
		case ECHECCAPTURE : retour ="ECHEC CAPTURE ";
			break;
		case ERREURACCESPORT : retour ="ERREUR ACCES PORT ";
			break;
		default :
			retour = "{\n\t\"LATITUDE\":"+string(laLatitude)+",\n" + "\t\"LONGITUDE\":"+string(laLongitude)+"\n}\n";
			break;
	}
	return retour;
}


string Collecteur::geolocaliser(int identifiant)
{
	char laLatitude[10];
	char laLongitude[10];
	int erreur=0;
	string retour;
	if (!listeEnregistrements.empty()) {
		erreur = listeEnregistrements.back()->localiser(laLatitude, laLongitude);
	}
    switch (erreur)
	{
		case MAUVAISETRAME : retour ="MAUVAISE TRAME ";
			break;
		case ALERTE : retour ="ALERTE GPS non pr�t  ";
			break;
		case ERREURCHECKSUM : retour ="ERREUR DE CHECKSUM ";
			break;
		case ECHECCAPTURE : retour ="ECHEC CAPTURE ";
			break;
		case ERREURACCESPORT : retour ="ERREUR ACCES PORT ";
			break;
		default :
			retour = "{\n\t\"LATITUDE\":"+string(laLatitude)+",\n" + "\t\"LONGITUDE\":"+string(laLongitude)+"\n}\n";
			break;
	}
	return retour;
}


string Collecteur::obtenirIntensiteLumineuse()
{
	float lIntensiteLumineuse;
	int erreur=0;
	if (!listeEnregistrements.empty()) {
		erreur = listeEnregistrements.back()->caracteriserAmpoule(lIntensiteLumineuse);
	}
	return "{\"luminosite\":\"" + to_string(lIntensiteLumineuse) +  "\"}";
}

string Collecteur::obtenirIntensiteLumineuse(int identifiant)
{

	return "eeeeeeeeeeeeeeeee";
}


