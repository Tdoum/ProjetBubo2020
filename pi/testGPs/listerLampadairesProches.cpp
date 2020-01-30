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
	Collecteur *leCollecteur= new Collecteur();
	std::vector<Enregistrement*> laListeEnregistrements=leCollecteur->chercherEnregistrements();
	cout << HTTPHTMLHeader();

		  cout<<"{\"enregistrement\":\n\t[";
		  //----------------------------
	//for(vector<vector<string> >::iterator it = valeur.begin(); it< valeur.end(); it++)
 //   	{
 //       	vector<string> row = *it;
	//	//printf("\n\t\t{");
	//	for(int i = 0; i < row.size(); i++){
	//		printf("\n\t\t\t\"%s\":\"%s\"%s", colonneNames.at(i).c_str(), row.at(i).c_str(), (i+1) < row.size() ? ",":"");
	//	}
 //       printf("\n\t\t}%s", it+ 1 == valeur.end() ? "": ",");
 //   }
 //printf("\n\t]\n}");
 //----------------------------
		  for (std::vector<Enregistrement*>::iterator it = laListeEnregistrements.begin() ; it != laListeEnregistrements.end(); ++it)
		  {
			  cout<<"\n\t\t{";
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
			  cout<<"\n\t\t\t\"ID\":\""<<identifiantE<<"\",";


			  ((Enregistrement*)*it)->getLampadaire(streetlight,height,ULOR,albedo);
			  ((Enregistrement*)*it)->getAmpoule(lamp,fluxLum,power);
			  cout<<"\n\t\t\t\"POWER\":\""<<power<<"\",";
			  cout<<"\n\t\t\t\"ALBEDO\":\""<<albedo<<"\",";
			  cout<<"\n\t\t\t\"FLUX\":\""<<fluxLum<<"\",";
			  cout<<"\n\t\t\t\"BUBOID\":\""<<((Enregistrement*)*it)->getBuboID() <<"\",";
			  cout<<"\n\t\t\t\"LAMP\":\""<<lamp <<"\",";
			  cout<<"\n\t\t\t\"STREETLIGHT\":\""<<streetlight <<"\",";
			  cout<<"\n\t\t\t\"HEIGHT\":\""<<height <<"\",";

			  ((Enregistrement*)*it)->getGeolocalisation(latitude,longitude);
			  string laLongitude=longitude; 
			  string laLatitude=latitude;
			  cout<<"\n\t\t\t\"LATITUDE\":\""<<laLatitude <<"\",";
			  cout<<"\n\t\t\t\"LONGITUDE\":\""<<laLongitude <<"\",";
			  
			  ((Enregistrement*)*it)->getGalerie(nbimages);
			  cout<<"\n\t\t\t\"NBIMAGES\":\""<<nbimages <<"\",";
			  town = ((Enregistrement*)*it)->getAgglomeration();
			  cout<<"\n\t\t\t\"TOWN\":\""<<town <<"\",";
			  street = ((Enregistrement*)*it)->getRue();
			  cout<<"\n\t\t\t\"STREET\":\""<<street <<"\",";
			  cout<<"\n\t\t\t\"ULOR\":\""<<ULOR<<"\",";
			  ((Enregistrement*)*it)->getHorodatage(date);
			  string laDate(date, 6); 
			  cout<<"\n\t\t\t\"DATE\":\""<<laDate<<"\",";
 			  notes=((Enregistrement*)*it)->getNotes();
			  cout<<"\n\t\t\t\"NOTES\":\""<<notes<<"\"";
			  cout<<"\n\t\t}";
			  if (!(it+1 == laListeEnregistrements.end())) cout<<",";
		  }
			  cout<<"\n\t]\n}";

}