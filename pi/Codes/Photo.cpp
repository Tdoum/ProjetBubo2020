#include <exception>
#include <dirent.h>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdio>
#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
using namespace std;

#include "Photo.h"
#include "Galerie.h"

void Photo::uploadPhoto(string aPhoto, string aIdentifiant) {
	throw "Not yet implemented";
}

void Photo::setIdentifiant(string aIdentifiant) {
	this->_identifiant = aIdentifiant;
}

string Photo::getIdentifiant() {
	return this->_identifiant;
}

Photo::Photo(string photoRepertoire) {
    this->photoRepertoire = photoRepertoire;
}


Photo::~Photo() {
}

int Photo::getNbPhoto(string directory){
    DIR* dir = opendir(directory.c_str());
    dirent* entre = readdir(dir);
    int count = 0;
    while(entre){
	if(entre->d_type == DT_REG){
            string nomfichier = entre->d_name;
            if(nomfichier.find(".jpg", (nomfichier.length() - 4)) != string::npos)
		count++;
	}
	entre = readdir(dir);
    }
    return count;
}

bool Photo::ajoute(FormFile image, string enregistrement)
{
    ofstream fichier;
    string lien = photoRepertoire + enregistrement +"/"+enregistrement + to_string(getNbPhoto(photoRepertoire+enregistrement)+1)+ IMG_EXTENSION;
    fichier.open((char*)lien.c_str());
    if(fichier.is_open()){
        image.writeToStream(fichier);
        fichier.close();
        return true;
    }else{
        cout << "ERREUR : CANNOT OPEN FILE" << endl;
    }   return false;
    
}

bool Photo::supprime(string nom){
    
    string lien = photoRepertoire + nom;
    if(remove(lien.c_str()) != 0){
        cout << "ERREUR : SUPRESSION FILE" << endl;
        return false;
    }
    
    return true;
    
    
}