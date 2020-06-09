#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string const nomFichier("/home/playmaker/Config/scores.txt");
    ifstream monFlux(nomFichier.c_str());

    return 0;
}