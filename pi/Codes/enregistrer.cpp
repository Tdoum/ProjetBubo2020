#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "Enregistrement.h"
#include "BDD.h"
#include "Collecteur.h"
#include "Logger.h"

using namespace std;
using namespace cgicc;

int main()
{       Logger* monLogger = new Logger();
	//DÃ©claration des variables
	string identifiantCollecteur;
	string  aIdEnregistrement;
	int aId;
	string aAlbedo;
	string aFluxLum;
	string aIdRaspberry;
	string aTypeAmpoule;
	string aTypeLampadaire;
	string aHauteur;
	int puissance=0;
	double aLatitude;
	double aLongitude;
	int aNbImages;
	string aAgglo;
	string aNotes;
	string aRue;
	int aUlor=0;
	string aDate;
	//------------------------

	//DÃ©claration des CGI
	Cgicc cgi;
	const CgiEnvironment& env = cgi.getEnvironment();
	//-----------------------------------
	cout<<HTTPHTMLHeader();
monLogger->saveLog("Enregistrement ...");
			//--------------------------Récupération latitude -------------------------
			form_iterator fvalue = cgi.getElement("latitude"); //RÃ©cupÃ©ration valeur du champs "lattitude" 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) {
				aLatitude = atof((**fvalue).c_str()); // atof => convertit un string en double 
			} 
			//--------------------------Récupération Identifiant -------------------------
			fvalue = cgi.getElement("identifiant"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				aId = atoi((**fvalue).c_str());
			} 
			//--------------------------Récupération longitude -------------------------
			fvalue = cgi.getElement("longitude"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				aLongitude = atof((**fvalue).c_str()); // atof => convertit un string en double 
			} 
			//--------------------------Récupération typeLampadaire -------------------------
			fvalue = cgi.getElement("typeLampadaire"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				aTypeLampadaire = **fvalue;
			} 
			//--------------------------Récupération ulor -------------------------
			fvalue = cgi.getElement("ulor"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				aUlor = atoi((**fvalue).c_str()); // atoi => convertit un string en int  
			} 

			//--------------------------Récupération typeAmpoule -------------------------
			fvalue = cgi.getElement("typeAmpoule"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				aTypeAmpoule = **fvalue; 
			}
			//--------------------------Récupération hauteur -------------------------
			fvalue = cgi.getElement("hauteur"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				aHauteur = **fvalue;
			} 
			//--------------------------Récupération puissance -------------------------
			fvalue = cgi.getElement("puissance"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				puissance = atoi((**fvalue).c_str()); // atoi => convertit un string en int 
			} 
			//--------------------------Récupération albedo -------------------------
			fvalue = cgi.getElement("albedo"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				aAlbedo = **fvalue;
			} 

			//--------------------------Récupération agglomeration -------------------------
			fvalue = cgi.getElement("agglomeration"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				aAgglo = **fvalue;
			} 
			//--------------------------Récupération rue -------------------------
			fvalue = cgi.getElement("rue"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				aRue = **fvalue;
			} 
			//--------------------------Récupération notes -------------------------
			fvalue = cgi.getElement("notes"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				aNotes = **fvalue;
			} 
			//--------------------------Récupération fluxlum -------------------------
			fvalue = cgi.getElement("fluxlum"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				aFluxLum = **fvalue;
			} 
			//--------------------------Récupération nbImage -------------------------
			fvalue = cgi.getElement("nbImage"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				aNbImages = atoi((**fvalue).c_str()); // atoi => convertit un string en int
			} 
			//------------------------RÃ©cupÃ©ration date---------------------------
			fvalue = cgi.getElement("date"); 
                        if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
                                aDate = **fvalue;
                        } 


//fichier<<"\r\n" << env.getPostData(); no treated

			//Instanciation des classes Enregistrement.cpp BDD.cpp et Collecteur.cpp
			Enregistrement* enregistrement = new Enregistrement(aAlbedo, aFluxLum, aIdRaspberry,  aTypeAmpoule,  aTypeLampadaire,aHauteur, aLatitude,  aLongitude, aNbImages, aAgglo,  aRue,  aUlor, aDate, aNotes, puissance);


			Collecteur* monCollecteur = new Collecteur();


			//Enregistrement dans la BDD
			enregistrement=monCollecteur->creerEnregistrement(enregistrement);
			//----------------------------------------------------------------------


			monLogger->saveLog("Enregistrement : OK");

    return 0;
}
