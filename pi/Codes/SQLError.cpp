#include "SQLError.h"

SQLError::SQLError(std::string msg): Error(msg)
{
}

SQLError::~SQLError()
{
    //dtor
}

