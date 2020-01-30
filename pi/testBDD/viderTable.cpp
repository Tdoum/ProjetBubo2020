#include <iostream>
#include <cstdio>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>
#include <string>
#include "BDD.h"
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
	//Déclaration des variables

	//int aId;

	////------------------------

	////Déclaration des CGI
	//Cgicc cgi;
	//const CgiEnvironment& env = cgi.getEnvironment();
	//-----------------------------------
	//string mon_fichier = "/home/pi/test.txt";
 //   ofstream fichier(mon_fichier.c_str(),  ios::out | ios::trunc);  //d�claration du flux et ouverture du fichier

			//Instanciation de la classe Collecteur.cpp
		    Collecteur *leCollecteur= new Collecteur();


			if (leCollecteur->viderTable()) 	cout<<HTTPHTMLHeader();
							//fichier << "Record removed" << endl; 
	//}
}

