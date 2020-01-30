#ifndef SQLERROR_H
#define SQLERROR_H

#include "Error.h"

class SQLError : public Error
{
    public:
        SQLError(std::string msg);
        ~SQLError();
    protected:

    private:
};

#endif // SQLERROR_H
