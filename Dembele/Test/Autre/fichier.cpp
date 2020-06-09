#include <iostream>
#include <fstream>
using namespace std;
 
int main()
{
        ifstream fichier("/home/playmaker/pi/Config/test.conf", ios::in);  // on ouvre
        
        if(fichier)
        {
                char caractere;  // notre variable où sera stocké le caractère
                fichier.get(caractere);  // on lit un caractère et on le stocke dans caractere
                cout << caractere;  // on l'affiche
 
                fichier.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;
 
        return 0;
}