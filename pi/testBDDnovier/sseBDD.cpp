#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>
#include <sqlite3.h>

#include <random>

using namespace std;

int main ()
{
	sqlite3 *db;
	string mon_fichier = "/home/pi/bubo.log";
    ofstream fichier(mon_fichier.c_str(),  ios::out | ios::app  );
	if(sqlite3_open("/home/pi/bdd/Enregistrement.db", &db))
		fichier<<"Can't open database:  "<<sqlite3_errmsg(db)<<endl;

	int rc;
	sqlite3_stmt *stmt;
	vector<vector<string> > valeur;
	vector<string> colonneNames;

	string colonneName;
	rc = sqlite3_prepare_v2(db, "SELECT * FROM Enregistrements ORDER BY ID DESC LIMIT 5000", -1, &stmt, 0);

	if( rc==SQLITE_OK ){
		int nbColonne = sqlite3_column_count(stmt);
		int result = 0;
		while(true)
		{
			result = sqlite3_step(stmt);

			if(result == SQLITE_ROW)
			{
				vector<string> enregistrement;
				for(int i = 0; i < nbColonne; i ++)
				{

					if (sqlite3_column_text(stmt, i))
						enregistrement.push_back((char*)sqlite3_column_text(stmt, i));
					else enregistrement.push_back(" ");
					colonneName = sqlite3_column_name(stmt, i);
					for (int j=0;j<colonneName.length();j++)
						colonneName[j]=toupper(colonneName[j]);

					colonneNames.push_back(colonneName);
					//colonneNames.push_back(sqlite3_column_name(stmt, i));
				}
				valeur.push_back(enregistrement);

			}else
			{
				break;
			}
		}
	}
	random_device rd; 
	mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<> dis(1, 6);
	cout<<"Content-Type: text/event-stream\r\n";
	//cout<<"Cache-Control: no-cache\r\n";
	//cout<<"Connection: keep-alive\r\n";
	do
	{
		//cout<<"event: ping\n";
		cout<< "retry: 10000\r\n";
		cout<< "data: Le ciel est bleu\n\n";//\"ID\":\""<< dis(gen)<<"\"\n";
		cout<<flush;
		this_thread::sleep_for (chrono::seconds(3));
	}
	while(1);

}