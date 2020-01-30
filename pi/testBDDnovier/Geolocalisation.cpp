// version avec moyennage (pour version validée voir Geolocalisation2.cpp
#include <exception>
#include <cstdio>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iostream>
#include <iomanip>
#include <algorithm> 
#include <cmath>


#include "Geolocalisation.h"

using namespace std;


Geolocalisation::Geolocalisation(GPS *unGPS)
{
	this->leGPS = unGPS;
}

Geolocalisation::Geolocalisation()
{

}


int Geolocalisation::filtrage (array <vector<double>,2> lotCoordonnees, double &latitude, double &longitude)
{
	double sommeLat=0;
	double sommeLong=0;
	lotCoordonnees[0].erase( min_element(lotCoordonnees[0].begin(),lotCoordonnees[0].end()));
	lotCoordonnees[1].erase( min_element(lotCoordonnees[1].begin(),lotCoordonnees[1].end()));
	lotCoordonnees[0].erase( max_element(lotCoordonnees[0].begin(),lotCoordonnees[0].end()));
	lotCoordonnees[1].erase( max_element(lotCoordonnees[1].begin(),lotCoordonnees[1].end()));

	for (std::vector<double>::iterator it = lotCoordonnees[0].begin() ; it != lotCoordonnees[0].end(); ++it)
	{
		sommeLat+=(*it);
	}
	for (std::vector<double>::iterator it = lotCoordonnees[1].begin() ; it != lotCoordonnees[1].end(); ++it)
	{
		sommeLong+=(*it);
	}
	latitude=sommeLat/lotCoordonnees[0].size();
	longitude=sommeLong/lotCoordonnees[1].size();

}


int Geolocalisation::localiser(char clatitude[10],char clongitude[10])
{
	array <vector<double>,2> lotCoordonnees;
	vector<char> trameRMC;
	vector<char> messages;
	int erreur=0;
	double mlatitude=0, mlongitude=0;
	int nbreIterations = 0;
	vector<char>::const_iterator	lit,lend;
	do 
	{
		/*Lecture d'une salve de trames sur le port du GPS*/
		erreur = leGPS->lire ();

		if (erreur >= 0) 
		{

			/*on vide la trameRMC précédente*/
			trameRMC.erase(trameRMC.begin(),trameRMC.end());

			/* Extraction de la nouvelle trame RMC */
			erreur = leGPS->extraireRMC( trameRMC);

			if (erreur>0) 
			{
				/* si la trame est correcte ((A) + Checksum OK) extraire la Latitude puis la longitude*/
				extraireLatitudeRMC(trameRMC,mlatitude);
				extraireLongitudeRMC(trameRMC,mlongitude);
				/* Remplissage d'un tableau de double en vue d'un filtrage*/
				lotCoordonnees[0].push_back(mlatitude);
				lotCoordonnees[1].push_back(mlongitude);
				mlatitude=0;
				mlongitude=0;
				erreur=1;
			}
		}
		nbreIterations=nbreIterations+1;
		this_thread::sleep_for(std::chrono::milliseconds(2));
		//nombre d'itération
	} while (nbreIterations<8);
	if ((lotCoordonnees[0].empty()) || (lotCoordonnees[0].size() < 6)) return ECHECCAPTURE ;

	/* calcul coordonnées */
	filtrage (lotCoordonnees, mlatitude, mlongitude);
	if ((abs(mlatitude)>90) || (abs(mlongitude)>180)) return ECHECCAPTURE ;


	/* Conversion en chaine de caractères du double obtenu*/
	snprintf(clatitude,11,"%3.7f",mlatitude);
	
	snprintf(clongitude,11,"%3.7f",mlongitude);
	/* Mise à jour des attributs de Geolocaliser */
	for (int i=0;i<11;i++)
	{
		if (clongitude[i]>43 && clongitude[i]<58)
			longitude[i]=clongitude[i];
		else longitude[i]=0x30;

	}
	for (int i=0;i<11;i++)
	{

		if (clatitude[i]>43 && clatitude[i]<58)
			latitude[i]=clatitude[i];
		else latitude[i]=0x30;
	}

	return 1;
}

int Geolocalisation::localiserSF(char clatitude[10],char clongitude[10])
{
	vector<char> trameRMC;
	int erreur=0;
	double mlatitude=0, mlongitude=0;
	vector<char>::const_iterator	lit,lend;

	/*Lecture d'une salve de trames sur le port du GPS*/
	erreur = leGPS->lire ();
	if (erreur < 0) return erreur ;

	/* Extraction de la trame RMC */
	erreur = leGPS->extraireRMC( trameRMC);
	if (erreur<=0) return erreur;

	/* si la trame est correcte ((A) + Checksum OK) extraire la Latitude puis la longitude*/
	extraireLatitudeRMC(trameRMC,mlatitude);
	extraireLongitudeRMC(trameRMC,mlongitude);

	/* Conversion en chaine de caractères du double obtenu*/
	snprintf(clatitude,10,"%3.7f",mlatitude);
	
	snprintf(clongitude,10,"%3.7f",mlongitude);
	/* Mise à jour des attributs de Geolocaliser */
	for (int i=0;i<10;i++)
	{
		if (clongitude[i]>43 && clongitude[i]<58)
			longitude[i]=clongitude[i];
		else longitude[i]=0x30;

	}
	for (int i=0;i<10;i++)
	{

		if (clatitude[i]>43 && clatitude[i]<58)
			latitude[i]=clatitude[i];
		else latitude[i]=0x30;
	}

	return erreur;
}

int Geolocalisation::extraireLatitudeRMC(std::vector<char> trameRMC, double &latitude )
{
	vector<char>::const_iterator	lit,lend;
	char cdegres[2]={0};
	char cminutes[7]={0};
	double minutes, degres;
	char clatitude[10];
	// On atteind le champs "ALERTE"
	lit= find(trameRMC.begin(), trameRMC.end(),'A');
	// On saute le champs "ALERTE"
	advance(lit,1);
	lend = trameRMC.end();
	for (int i=0;i<10;i++)
	{
		clatitude[i]=*++lit;
		if (clatitude[i]==',') 
		{
			clatitude[i]=0;
			break;
		}
	}
	/* Conversion de la latitude fournie par la trame 
	4916.45,N = Latitude 49°16.45'  en degrés  49.274166°*/
	for (int i=0;i<2;i++)
	{
		cdegres[i]=clatitude[i];
	}
	for (int i=2;i<9;i++)
	{
		cminutes[i-2]=clatitude[i];
	}

	// Conversion en double des chaines de caractères
	minutes = std::strtod(cminutes,NULL);
	degres = std::strtod(cdegres,NULL);
	//calcul de conversion en degrés
	degres = degres + minutes/60;
	advance(lit,-1);
	lit= find(lit, lend,',');
	advance(lit,1);
	if (*lit=='S') latitude = -1*degres;
	else latitude = degres;
	//latitude = degres;
	return 1;
}

int Geolocalisation::extraireLongitudeRMC(std::vector<char> trameRMC, double &longitude)
{
	vector<char>::const_iterator	lit,lend;
	char cdegres[3]={0};
	char cminutes[7]={0};
	double minutes, degres;
	char clongitude[10];
	// Atteindre le champs "ALERTE"
	lit= find(trameRMC.begin(), trameRMC.end(),'A');
	// On passe le champs "ALERTE"
	advance(lit,2);
	lend = trameRMC.end();
	// On passe le champs "Latitude"
	lit= find(lit, lend,',');
	// On passe le champs "Direction"
	advance(lit,2);
	for (int i=0;i<11;i++)
	{
		clongitude[i]=*++lit;
		if (clongitude[i]==',') 
		{
			clongitude[i]=0;
			break;
		}
	}

	/* Conversion de la longitude fournie par la trame 
	12311.12,W = Longitude 123°11.12' Ouest en degrés -123,185333°*/
	for (int i=0;i<3;i++)
	{
		cdegres[i]=clongitude[i];
	}
	for (int i=3;i<9;i++)
	{
		cminutes[i-3]=clongitude[i];
	}
	// Conversion en double des chaines de caractères
	minutes = std::strtod(cminutes,NULL);
	degres = std::strtod(cdegres,NULL);
	//calcul de conversion en degrés
	degres = degres + minutes/60;
	advance(lit,-1);
	lit= find(lit, lend,',');
	advance(lit,1);
	if (*lit=='W') longitude = -1*degres;
	else longitude = degres;

	return 1;
}


void Geolocalisation::setLatitude(char aLatitude[10]){

        for (int i=0;i<10;i++)
        {
                latitude[i]=aLatitude[i];
        }
}
void Geolocalisation::setLongitude(char aLongitude[10]){

        for (int i=0;i<10;i++)
        {
                longitude[i]=aLongitude[i];
        }
}


void Geolocalisation::getLongitude(char alongitude [10]) {

        for (int i=0;i<10;i++)
        {
                alongitude[i]=longitude[i];
        }
}

void Geolocalisation::getLatitude(char alatitude[10]) {

        for (int i=0; i<10;i++)
        {

                alatitude[i]=latitude[i];

        }


  }


