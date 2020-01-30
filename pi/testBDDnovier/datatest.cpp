#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <sqlite3.h>
#include <ctype.h>
#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
#include "cgicc/HTTPHTMLHeader.h"
#include "cgicc/HTMLClasses.h"

using namespace std;
using namespace cgicc;

int main(int argc, char * argv[]) {
	sqlite3 *db;
	if(sqlite3_open("/home/pi/bdd/Enregistrement.db", &db))
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

	Cgicc formData;
	int rc;
	cout << HTTPHTMLHeader();
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
		//int cols = sqlite3_column_count(stmt);
		//for (int i=0; i<cols; i++)
		//{

		//}
	}
	else{
	}

	printf("{\"enregistrement\":\n\t[");
	for(vector<vector<string> >::iterator it = valeur.begin(); it< valeur.end(); it++)
    	{
        	vector<string> row = *it;
		printf("\n\t\t{");
		for(int i = 0; i < row.size(); i++){
			printf("\n\t\t\t\"%s\":\"%s\"%s", colonneNames.at(i).c_str(), row.at(i).c_str(), (i+1) < row.size() ? ",":"");
		}
        printf("\n\t\t}%s", it+ 1 == valeur.end() ? "": ",");
    }
 printf("\n\t]\n}");


}
