
#ifndef ERROR_H
#define ERROR_H

#include <exception>
#include <string>


class Error : public std::exception
{
    public:
        std::string message;
        Error(std::string msg);
        ~Error();
        const char* what();
    protected:

    private:
};

#endif // ERROR_H
