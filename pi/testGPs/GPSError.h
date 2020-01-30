#ifndef GPSERROR_H
#define GPSERROR_H
#include <iostream>
#include "Error.h"
#include <string>
using namespace std;

class GPSError : public Error
{
    public:
        GPSError(string msg);
        ~GPSError();
    protected:

    private:
};

#endif // GPSERROR_H
