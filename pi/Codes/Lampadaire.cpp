#include <string>
using namespace std;

#include "Lampadaire.h"
#include "Enregistrement.h"

void  Lampadaire::setType(string aType) {
	this->_type = aType;
}

string  Lampadaire::getType() {
	return this->_type;
}

void  Lampadaire::setHauteur(string aHauteur) {
	this->_hauteur = aHauteur;
}

string  Lampadaire::getHauteur() {
	return this->_hauteur;
}

void  Lampadaire::setULOR(int aULOR) {
	this->_uLOR = aULOR;
}

int  Lampadaire::getULOR() {
	return this->_uLOR;
}

void  Lampadaire::setAlbedo(string aAlbedo) {


	_albedo = aAlbedo;

}

string  Lampadaire::getAlbedo() {
	return this->_albedo;
}

Lampadaire::Lampadaire()
{
	_albedo=0.3;
}
