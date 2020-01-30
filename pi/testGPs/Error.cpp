#include "Error.h"
#include <errno.h>
/* Initialise la variable message avec le msg d'erreur passer à l'objet */
Error::Error(std::string msg) : message(msg)
{

}

Error::~Error()
{
    //dtor
}

const char* Error::what(){
    return message.c_str();
}
