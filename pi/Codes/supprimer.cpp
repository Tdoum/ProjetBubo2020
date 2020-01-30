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
#include <fstream>
#include "BDD.h"
#include <stdio.h>
#include "Lampadaire.h"
#include "Collecteur.h"


#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"
#include <cgicc/CgiEnvironment.h>
#include <cgicc/FormEntry.h>


using namespace std;
using namespace cgicc;

int main(){
	//DÃ©claration des variables

	int aId;

	//------------------------

	//DÃ©claration des CGI
	Cgicc cgi;
	const CgiEnvironment& env = cgi.getEnvironment();
	//-----------------------------------
	string mon_fichier = "/home/pi/test.txt";
    ofstream fichier(mon_fichier.c_str(),  ios::out | ios::trunc);  //déclaration du flux et ouverture du fichier
	cout<<HTTPHTMLHeader();
    if(fichier)  // si l'ouverture a réussi
        {

			//--------------------------Récupération ID -------------------------
			form_iterator fvalue  = cgi.getElement("ID"); 
			if( !fvalue->isEmpty() && fvalue != (*cgi).end()) { 
				fichier << "L'ID BDD est : " << **fvalue << endl; 
				aId = atoi((**fvalue).c_str()); // atoi => convertit un string en int 
			} 
			else 
				fichier << "No text find for ID" << endl; 
			//fichier<<"\r\n" << env.getPostData(); no treated

			//Instanciation de la classe Collecteur.cpp
		    Collecteur *leCollecteur= new Collecteur();


			leCollecteur->supprimerEnregistrement(aId);
							fichier << "Record removed" << endl; 
	}
}

