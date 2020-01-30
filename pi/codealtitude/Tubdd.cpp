

#include <cstdlib>
#include <vector>
#include <iostream>
#include "BDD.h"
using namespace std;

/*
 * 
 */
int main() {

	//TU Sauver un enregistrement
    Enregistrement* unEnregistrement= new Enregistrement("0.3","300.0","Incandescence","Projecteur sur mat","5.0",43.614468,1.3054,100,0,
		"Colomiers","rue des coquelicots",15,"250519","pasdenote",230);
    BDD* uneBDD = new BDD();
    uneBDD->sauvegarderDonneesEnregistrement(unEnregistrement,"0000000020f09bce");

	//TU modifier un enregistrement
	uneBDD->modifierEnregistrement(21, 230, "0.4","300.0","000000002ed09bce","Halogène","Projecteur sur mat","5.0",43.6182,1.3054,100,0,
		"Colomiers","rue des coquelicots",15,"260519","pasdenote");


	//TU obtenirListeDesEnregistrements

	char date[6];
	vector<Enregistrement*> laListe = uneBDD->obtenirListeDesEnregistrements();
	vector<Enregistrement*>::iterator lit;
	for (lit=laListe.begin();lit!=laListe.end();++lit)
	{
		(*lit)->getHorodatage(date);
		cout<<string(date,6)<<endl;
		cout<<(*lit)->getIdentifiant()<<endl;

	}

	//TU supprimerEnregistrement
	int num;
	cout<<"Quel enregistrement souhaitez vous supprimer?"<<endl;
	cin >> num;

	uneBDD->supprimerEnregistrement(num);

	laListe = uneBDD->obtenirListeDesEnregistrements();
	
	for (lit=laListe.begin();lit!=laListe.end();++lit)
	{
		(*lit)->getHorodatage(date);
		cout<<string(date,6)<<endl;
		cout<<(*lit)->getIdentifiant()<<endl;

	}

    
    return 0;
}

