//ligne de compilation : g++ test.cpp -o test.cgi -lcgicc
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"


using namespace std;
using namespace cgicc;

int main()
{       

	//DÃ©claration des CGI
	Cgicc cgi;
	const CgiEnvironment& env = cgi.getEnvironment();

		//-----------------------------------
	string mon_fichier = "/home/pi/Config/test.txt";
        ofstream fichier(mon_fichier.c_str(),  ios::app);  //déclaration du flux et ouverture du fichier
	//-----------------------------------
	cout<<HTTPHTMLHeader();
        //--------------------------Récupération theCar -------------------------
        form_iterator fvalue = cgi.getElement("theCar"); //RÃ©cupÃ©ration valeur du champs "lattitude" 
        string vazz = cgi.getElement("theCar");
        if( !fvalue->isEmpty() && fvalue != (*cgi).end()) {
                fichier << **fvalue << endl;
                cout << **fvalue << endl;
        } 
        else 
                fichier << "No text selected for theCar" << endl; //Retourne ce texte si aucune valeur n'est entrÃ©e 

cout<< "salut toi" << vazz << endl;

    return 0;
}