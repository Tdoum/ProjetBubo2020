#include "Horodatage.h"

using namespace std;

int main()
{
	
	char date [6];
	char heure [6];
	bool fin;
	GPS* unGPS = new GPS();
	Horodatage* lHorodatage = new Horodatage(unGPS);
	lHorodatage->setVCond(fin);
	//test Geo et Horo
	
	
	lHorodatage->dater();
	cout<<"dater completed OK"<<endl;

	lHorodatage->getHeure(heure);
	cout << heure << endl;
	lHorodatage->getDate(date);
	cout << string(date,6) << endl;
	system("date" + date[2]+date[3]+date[0]+date[1]+heure[0]+heure[1]+heure[2]+heure[3]+date[4]+date[5]);
}

