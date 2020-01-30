#include <exception>
#include <string>
using namespace std;

#include "Ampoule.h"
#include "Luxmetre.h"

Ampoule::Ampoule(){
	luxmetre = new Luxmetre();
}

Ampoule::~Ampoule() {
}

float Ampoule::mesurerILux(){
    return luxmetre->lireLux();
}

void  Ampoule::setType(string aType) {
	this->_type = aType;
}

string  Ampoule::getType() {
	return this->_type;
}

void  Ampoule::setIntensiteLumineuse(string aIntensiteLumineuse) {
	this->_intensiteLumineuse = aIntensiteLumineuse;
}

string  Ampoule::getIntensiteLumineuse() {
	return this->_intensiteLumineuse;
}

void  Ampoule::setPuissance(int aPuissance) {
	this->_puissance = aPuissance;
}

int  Ampoule::getPuissance() {
	return this->_puissance;
}

