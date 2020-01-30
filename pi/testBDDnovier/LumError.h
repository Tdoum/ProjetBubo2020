#ifndef LUMERROR_H
#define LUMERROR_H

#include "Error.h"

class LumError : public Error
{
    public:
        LumError(std::string msg);
        ~LumError();

    protected:

    private:
};

#endif // LUMERROR_H
