#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sqlite3.h>
#include <ctype.h>
#include <chrono>
#include <thread>
#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

#include "Collecteur.h"
using namespace std;
using namespace cgicc;

int main()
{
	cout<<"Content-Type: text/event-stream\r\n\n";  

	Collecteur *leCollecteur= new Collecteur();
	std::vector<Enregistrement*> laListeEnregistrements=leCollecteur->chercherEnregistrements();

		cout<< "data: ";
		  cout<<"{\"enregistrement\":\t[";
		   
		  for (std::vector<Enregistrement*>::iterator it = laListeEnregistrements.begin() ; it != laListeEnregistrements.end(); ++it)
		  {
			  cout<<"\t\t{";
			  string lamp;
  			  string streetlight;
			  string height;
			  int ULOR;
			  int power;
			  string  albedo;
			  string fluxLum;
			  int nbimages;
			  char date [7];
			  char longitude[10];
			  char latitude[10];
			  int identifiantE;
			  string  town;
			  string  street;
			  string notes;

			  identifiantE = ((Enregistrement*)*it)->getIdentifiant();
			  cout<<" \t\t\t\"ID\":\""<<identifiantE<<"\",";


			  ((Enregistrement*)*it)->getLampadaire(streetlight,height,ULOR,albedo);
			  ((Enregistrement*)*it)->getAmpoule(lamp,fluxLum,power);
			  cout<<"\t\t\t\"POWER\":\""<<power<<"\",";
			  cout<<" \t\t\t\"ALBEDO\":\""<<albedo<<"\",";
			  cout<<"\t\t\t\"FLUX\":\""<<fluxLum<<"\",";
			  cout<<"\t\t\t\"BUBOID\":\""<<((Enregistrement*)*it)->getBuboID() <<"\",";
			  cout<<"\t\t\t\"LAMP\":\""<<lamp <<"\",";
			  cout<<"\t\t\t\"STREETLIGHT\":\""<<streetlight <<"\",";
			  cout<<"\t\t\t\"HEIGHT\":\""<<height <<"\",";

			  ((Enregistrement*)*it)->getGeolocalisation(latitude,longitude);
			  string laLongitude=longitude; 
			  string laLatitude=latitude;
			  cout<<"\t\t\t\"LATITUDE\":\""<<laLatitude <<"\",";
			  cout<<"\t\t\t\"LONGITUDE\":\""<<laLongitude <<"\",";
			  
			  ((Enregistrement*)*it)->getGalerie(nbimages);
			  cout<<"\t\t\t\"NBIMAGES\":\""<<nbimages <<"\",";
			  town = ((Enregistrement*)*it)->getAgglomeration();
			  cout<<"\t\t\t\"TOWN\":\""<<town <<"\",";
			  street = ((Enregistrement*)*it)->getRue();
			  cout<<"\t\t\t\"STREET\":\""<<street <<"\",";
			  cout<<"\t\t\t\"ULOR\":\""<<ULOR<<"\",";
			  ((Enregistrement*)*it)->getHorodatage(date);
			  string laDate(date, 6); 
			  cout<<"\t\t\t\"DATE\":\""<<laDate<<"\",";
 			  notes=((Enregistrement*)*it)->getNotes();
			  cout<<"\t\t\t\"NOTES\":\""<<notes<<"\"";
			  cout<<"\t\t}";
			  if (!(it+1 == laListeEnregistrements.end())) cout<<",";
		  }
			  cout<<"\t]}\n\n";
		cout<<flush;
		this_thread::sleep_for (chrono::seconds(3));

}