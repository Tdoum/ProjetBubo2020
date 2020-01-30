#include <exception>
#include <unistd.h>
#include <fstream>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <cmath>
#include <iostream>
#include <cerrno>
#include <cstdio>
#include <cstring>
using namespace std;

#include "Luxmetre.h"
#include "LumError.h"


Luxmetre::Luxmetre(){
}

float Luxmetre::lireLux(){
	int fd = init();
    reveilleCapteur();
    setRegistreTemps();
    sleep(1);
    char reg[1] = {CH0_ADDR};
	write(fd, reg, 1);
    char *data = lireCapteur();
    float  visibleEtInfrarouge = (data[1] * 256 + data[0]);
    float infrarouge = (data[3] * 256 + data[2]);

    return visibleEtInfrarouge-infrarouge;

}


char* Luxmetre::lireCapteur(){
    char data[4] = {0};
    if(read(fd, data, 4) != 4){
        LumError* lerr = new LumError(std::string("Erreur Read :")+std::string(std::strerror(errno)));
        throw lerr;
    }
    return data;
}
/*
 * Reveille le capteur
 */
void Luxmetre::reveilleCapteur(){
    /* Ajout dans config[] des registres afin de réveiller le capteur*/
    char config[2] = {CONTROL_REGISTER,POWER_ON};

    ecritureSurCapteur(config);
}

/*
 * Registre de temps
 */
 void Luxmetre::setRegistreTemps(){
     /* Ajout dans config[] des registres de temps*/
     char config[2] = {TIME_REGISTER, TIME_INTEGRATION};
     ecritureSurCapteur(config);
 }

 void Luxmetre::ecritureSurCapteur(char* buffer){
    write(fd,buffer, 2);
 }
/*
 * Initialisation du capteur
 */
int Luxmetre::init(){
    /* Lecture du bus I2C */
    char* bus = (char*)"/dev/i2c-1";
    if((fd = open(bus, O_RDWR)) < 0){
        LumError* lerr = new LumError(std::string("Erreur open :")+std::string(std::strerror(errno)));
        throw lerr;
    }
    if(ioctl(fd, I2C_SLAVE, TSL2561_ADDR) < 0){
        LumError* lerr = new LumError(std::string("Erreur IOCTL !")+std::string(std::strerror(errno)));
        throw lerr;
    }
    return fd;
}

