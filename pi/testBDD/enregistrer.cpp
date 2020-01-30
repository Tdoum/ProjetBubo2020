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
	//int aId;
	string albedo;
	string fluxLum;
	string aIdRaspberry;
	string lamp;
	string streetlight;
	string height;
	int power;
	double aLatitude;
	double aLongitude;
	int aNbImages;
	string town;
	string aNotes;
	string street;
	int ULOR;
	string aDate;
	//------------------------

	//DÃ©claration des CGI
	Cgicc cgi;
	const CgiEnvironment& env = cgi.getEnvironment();

		//-----------------------------------
	string mon_fichier = "/home/pi/test.txt";
    ofstream fichier(mon_fichier.c_str(),  ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier
	//-----------------------------------
	cout<<HTTPHTMLHeader();
			//--------------------------Récupération latitude -------------------------
			form_iterator fvalue = cgi.getElement("latitude"); //RÃ©cupÃ©ration valeur du champs "lattitude" 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) {
				fichier << "La latitude est : " << **fvalue << endl;
				aLatitude = atof((**fvalue).c_str()); // atof => convertit un string en double 
			} 
			else 
				fichier << "No text entered for latitude" << endl; //Retourne ce texte si aucune valeur n'est entrÃ©e 

			//--------------------------Récupération longitude -------------------------
			fvalue = cgi.getElement("longitude"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
								fichier << "La longitude est : " << **fvalue << endl; 
				aLongitude = atof((**fvalue).c_str()); // atof => convertit un string en double 
			} 
			else 
				fichier << "No text entered for longitude" << endl; 
			//--------------------------Récupération typeLampadaire -------------------------
			fvalue = cgi.getElement("typeLampadaire"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				streetlight = **fvalue;
			} 
			
			//--------------------------Récupération ulor -------------------------
			fvalue = cgi.getElement("ulor"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				ULOR = atoi((**fvalue).c_str()); // atoi => convertit un string en int  
			} 
			else ULOR = 0;


			//--------------------------Récupération typeAmpoule -------------------------
			fvalue = cgi.getElement("typeAmpoule"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				lamp = **fvalue; 
			} 
			
			//--------------------------Récupération hauteur -------------------------
			fvalue = cgi.getElement("hauteur"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				height = **fvalue;
			} 

			//--------------------------Récupération puissance -------------------------
			fvalue = cgi.getElement("puissance"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				power = atoi((**fvalue).c_str()); // atoi => convertit un string en int 
			} 
			else power = 0;
			
			//--------------------------Récupération albedo -------------------------
			fvalue = cgi.getElement("albedo"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				albedo = **fvalue;
			} 
			

			//--------------------------Récupération agglomeration -------------------------
			fvalue = cgi.getElement("agglomeration"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				town = **fvalue;
			} 
		
			//--------------------------Récupération rue -------------------------
			fvalue = cgi.getElement("rue"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
 
				street = **fvalue;
			} 

			//--------------------------Récupération notes -------------------------
			fvalue = cgi.getElement("notes"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				aNotes = **fvalue;
			} 
			
			//--------------------------Récupération fluxlum -------------------------
			fvalue = cgi.getElement("fluxlum"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				fluxLum = **fvalue;
			} 


			//--------------------------Récupération nbImage -------------------------
			fvalue = cgi.getElement("nbImage"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				aNbImages = atoi((**fvalue).c_str()); // atoi => convertit un string en int
			} 
			else aNbImages=0;


			//--------------------------Récupération date -------------------------
			fvalue = cgi.getElement("date"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 

				aDate=(**fvalue).c_str(); // atoi => convertit un string en int
			} 


			//fichier<<"\r\n" << env.getPostData(); no treated

			//Instanciation des classes Enregistrement.cpp BDD.cpp et Collecteur.cpp
			Enregistrement* enregistrement = new Enregistrement(albedo, fluxLum, aIdRaspberry,  lamp,  streetlight,height, aLatitude,  aLongitude, aNbImages, town,  street,  ULOR, aDate, aNotes, power);


			Collecteur* monCollecteur = new Collecteur();


			//Enregistrement dans la BDD
			enregistrement=monCollecteur->creerEnregistrement(enregistrement);



						fichier<<endl;
			fichier<<"ENREGISTREMENT EFFECTUÃ‰ OK"<<endl;
	           fichier.close();  // on referme le fichier
			//----------------------------------------------------------------------
			/*	string identifiantCollecteur;
	string  aIdEnregistrement;
	//int aId;
	string albedo;
	string fluxLum;
	string aIdRaspberry;
	string lamp;
	string streetlight;
	string height;
	int power;
	double aLatitude;
	double aLongitude;
	int aNbImages;
	string town;
	string aNotes;
	string street;
	int ULOR;
	string aDate;*/
			char longitude[10];
			char latitude[10];
			char date[6];

			//retour nouvel enregistrement
			cout<<"{\n\t\"ID\":\""<<enregistrement->getIdentifiant()<<"\",";
			
			enregistrement->getLampadaire(streetlight,height,ULOR,albedo);
			enregistrement->getAmpoule(lamp,fluxLum,power);
			cout<<"\n\t\t\t\"POWER\":\""<<power<<"\",";
			cout<<"\n\t\t\t\"ALBEDO\":\""<<albedo<<"\",";
			cout<<"\n\t\t\t\"FLUX\":\""<<fluxLum<<"\",";
			cout<<"\n\t\t\t\"BUBOID\":\""<<enregistrement->getBuboID() <<"\",";
			cout<<"\n\t\t\t\"LAMP\":\""<<lamp <<"\",";
			cout<<"\n\t\t\t\"STREETLIGHT\":\""<<streetlight <<"\",";
			cout<<"\n\t\t\t\"HEIGHT\":\""<<height <<"\",";

			enregistrement->getGeolocalisation(latitude,longitude);
			string laLongitude=longitude; 
			string laLatitude=latitude;
			cout<<"\n\t\t\t\"LATITUDE\":\""<<laLatitude <<"\",";
			cout<<"\n\t\t\t\"LONGITUDE\":\""<<laLongitude <<"\",";
			
			enregistrement->getGalerie(aNbImages);
			cout<<"\n\t\t\t\"NBIMAGES\":\""<<aNbImages <<"\",";
			town = enregistrement->getAgglomeration();
			cout<<"\n\t\t\t\"TOWN\":\""<<town <<"\",";
			street = enregistrement->getRue();
			cout<<"\n\t\t\t\"STREET\":\""<<street <<"\",";
			cout<<"\n\t\t\t\"ULOR\":\""<<ULOR<<"\",";
			enregistrement->getHorodatage(date);
			string laDate(date, 6); 
			cout<<"\n\t\t\t\"DATE\":\""<<laDate<<"\","; //								retour =retour +"\t\"DATE\":\""+date+"\"\n}\n";
 			aNotes=enregistrement->getNotes();
			cout<<"\n\t\t\t\"NOTES\":\""<<aNotes<<"\"";
			cout<<"\n\t\t}\n";


    return 0;
}
