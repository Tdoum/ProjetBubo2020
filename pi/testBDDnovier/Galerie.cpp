#include <exception>
#include <string>
#include <vector>
using namespace std;

#include "Galerie.h"
#include "Enregistrement.h"
#include "Photo.h"

void  Galerie::ajouterPhotos(string aPhotos, int aNbre, string aIdentifiant) {
	throw "Not yet implemented";
}

void  Galerie::creerRepertoire(string aIdentifant) {
	throw "Not yet implemented";
}

void  Galerie::setNbrePhotos(int aNbrePhotos) {
	this->_nbrePhotos = aNbrePhotos;
}

int  Galerie::getNbrePhotos() {
	return this->_nbrePhotos;
}

