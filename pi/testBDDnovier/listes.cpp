#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"

using namespace std;
using namespace cgicc;

void lireListeAmpoule();
void lireListeLampadaire();
void lireListeULOR();
void lireListeAlbedo();

void lireListeAmpoule()
{

	ifstream fichier("listeAmpoule.txt", ios::in);
	string ligne;
	vector<string>::iterator it;
	vector<string> tableau;
	if(fichier)  // si l'ouverture a réussi
    {
		while(getline(fichier, ligne))
		{
			tableau.push_back(ligne);
		}
			cout << "{\n\t\"AMPOULE\":[";

		 for ( it=tableau.begin(); it!=tableau.end()-1;it++)
		{
			cout << "\""<<*it<<"\",";
		}

		cout << "\""<<tableau.back()<<"\"],\n";
	}
	else
	{
		cerr << "Erreur d'accès fichier listeAmpoule";
	}
}

void lireListeLampadaire()
{
    ifstream fichier("listeLampadaire.txt", ios::in);
                string ligne;
                vector<string>::iterator it;
	vector<string> tableau;
	if(fichier)  // si l'ouverture a réussi
    {
        while(getline(fichier, ligne))
        {
			tableau.push_back(ligne);
        }
        cout << "\n\t\"LAMPADAIRE\":[";

        for ( it=tableau.begin(); it!=tableau.end()-1;it++)
        {
            cout << "\""<<*it<<"\",";
        }

        cout << "\""<<tableau.back()<<"\"],\n";
	}
	else
	{
		cerr << "Erreur d'accès fichier listeLampadaire";
	}
}



void lireListeULOR()
{
    ifstream fichier("listeULOR.txt", ios::in);
    string ligne;
    vector<string>::iterator it;
	vector<string> tableau;
	if(fichier)  // si l'ouverture a réussi
    {
        while(getline(fichier, ligne))
        {
            tableau.push_back(ligne);
        }
            cout<<"\n\t\"ULOR\":[";

        for ( it=tableau.begin(); it!=tableau.end()-1;it++)
        {
            cout<<"\""<<*it<<"\",";
        }

		cout<<"\""<<tableau.back()<<"\"],\n";
	}
	else
	{
		cerr << "Erreur d'accès fichier listeULOR";
	}
}


void lireListeAlbedo()
{
    ifstream fichier("listeAlbedo.txt", ios::in);
    vector<string> tableau;
    string ligne;
 
    vector<string>::iterator it;
	if(fichier)  // si l'ouverture a réussi
    {
        while(getline(fichier, ligne))
        {
            tableau.push_back(ligne);
        }
        cout<<"\n\t\"ALBEDO\":[";

        for ( it=tableau.begin(); it!=tableau.end()-1;it++)
        {
            cout<<"\""<<*it<<"\",";
        }

		cout<<"\""<<tableau.back()<<"\"]\n}\n";
	}
	else
	{
		cerr << "Erreur d'accès fichier listeAlbedo";
	}
}

int main()
{
	cout<<HTTPHTMLHeader();
	lireListeAmpoule();
	lireListeLampadaire();
	lireListeULOR();
	lireListeAlbedo();
	return 0;
}




