#include <iostream>
#include <cstdio>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <iomanip>

#include "GPS.h"


using namespace std;


int main(){
	vector<char> messages;
	vector<char> trameRMC;
			cout<<"Ca commence"<<endl;
	int erreur=0;
	char latitude[10] = {0};
	char longitude[10] = {0};
	vector<char>::const_iterator	lit,lend;
	GPS legps;
			cout<<"Ca continu"<<endl;
	do 
	{

		messages.erase(messages.begin(),messages.end());
		trameRMC.erase(trameRMC.begin(),trameRMC.end());
		legps.lire ();
		messages= legps.getSalve();
		/*initialisation d'iterator pour le parcours et l'affichage de la liste messages*/
		lit=messages.begin(); 
		lend=messages.end(); 
		for (;lit!=lend;++lit)
		{
			cout << *lit ;
			if ( (char)*lit==0x24) cout <<endl;
		}
		cout<<endl;
		cout<<"Fin de la salve" <<endl;
		erreur = legps.extraireRMC( trameRMC);
		if (erreur<=0) cout<<"erreur Trame" <<endl;
	}
	while(erreur <=0);

	lit=trameRMC.begin();
	lend = trameRMC.end();
	cout<<'\n'<<"essais extraireRMC Trame ";
	for (;lit!=lend;++lit)
	{
		cout << *lit ;
	}
	cout<<endl;


	///*la trame doit absolument être vidée avant d'être réutilisée*/
	//trameRMC.erase(trameRMC.begin(),trameRMC.end());
	//list<char>  GPRMC={'$','G','P','G','G','A'};

	//erreur = legps.extraire( trameRMC,messages,GPRMC);
	//if (erreur!=1) cout<<"e-----------------rreur Trame n°" <<erreur <<endl;
	//else 
	//{
	//	lit=trameRMC.begin();
	//	lend = trameRMC.end();
	//	cout<<'\n'<<"Essais extraire Trame";
	//	for (;lit!=lend;++lit)
	//	{
	//		cout << *lit ;
	//	}
	//}
	//cout<<endl;
	/*la salve doit absolument être vidé avant d'être réutilisée*/
	messages.erase(messages.begin(),messages.end());

	return 0;
}