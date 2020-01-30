#include <exception>
#include <string>
#include <vector>
#include <sqlite3.h>
#include <iostream>
#include<fstream>

#include "BDD.h"
#include "Enregistrement.h"
#include "Lampadaire.h"
#include "Ampoule.h"
#include "Galerie.h"
#include "Geolocalisation.h"
#include "Horodatage.h"
#include "Logger.h"

using namespace std;
Logger * monLogger = new Logger();

BDD::BDD()
{
    //Chemin d'accés a la base de données
    _baseDeDonnees="/home/pi/bdd/Enregistrement.db";
    int rc;
    char * zErrMsg;
    /*Ouverture d'un accés a la base de données via son chemin d'accés
    * Si le fichier n'existe pas, la fonction sqlite3_open crée une
    * autre base avec ce nom
    */
    rc = sqlite3_open(_baseDeDonnees.c_str(), &db);
    if( rc )
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    }
    else
    {
        fprintf(stdout, "Opened database successfully\n");
        sqlite3_stmt *statement;
        string selectSql = "SELECT * FROM Enregistrements";
        sqlite3_prepare_v2(db,selectSql.c_str(), selectSql.length() ,&statement, NULL);
        int countColumn= sqlite3_column_count(statement);
	if(!countColumn)
	{
            std::string selectSql ="CREATE TABLE IF NOT EXISTS Enregistrements(id  INTEGER PRIMARY KEY AUTOINCREMENT  ,power INTEGER, albedo REAL,flux REAL, buboid TEXT NOT NULL,lamp TEXT  ,streetlight TEXT ,height REAL,latitude REAL NOT NULL ,longitude REAL NOT NULL,nbimages int ,town TEXT,street TEXT,ulor INTEGER, date TEXT, notes TEXT );";
            //Crée une table appelée Enregistrements qui a comme parametres toutes les données liées a l'enregistrement si elle existe pas deja.
            rc = sqlite3_exec(db, selectSql.c_str(), NULL, 0, &zErrMsg);
            if( rc != SQLITE_OK )
            {
                fprintf(stderr, "SQL error: %s\n", zErrMsg);
                sqlite3_free(zErrMsg);
            }
            else
            {
                fprintf(stdout, "Table created successfully\n");
            }
        }
    }
}

BDD::~BDD()
{
    sqlite3_close(db);
}

std::vector<Enregistrement> BDD::selectData(string requetesql)
{
}

std::vector<Enregistrement*> BDD::obtenirListeDesEnregistrements()
{
    //		**********************requete sql*****************************
    std:: string req1 = "SELECT * FROM Enregistrements ORDER BY ID DESC ";						//|declare req1 qui est la requete select* from enregistrement id classe par ordre
    const char *pzTest;
    sqlite3_stmt *stmt;                     //|objet d'instruction preparer
    vector<Enregistrement*>resultat;
    int rc = sqlite3_prepare_v2(db,req1.c_str(), req1.length() ,&stmt,&pzTest);			//|prepare la requete 
    if(!rc)
    {
        int nbColonne=sqlite3_column_count(stmt);
        //verifie qu'il y a des lignes disponibles
        while(rc == SQLITE_OK || rc == SQLITE_ROW)
        {
            //recuperation d'une ligne
            rc = sqlite3_step(stmt);
            if(rc == SQLITE_ROW)
            {
                vector<string> record;
                for(int i = 0; i < nbColonne; i++)
                {
                    if (sqlite3_column_text(stmt, i))
                    record.push_back((char*)sqlite3_column_text(stmt,i));
                    else record.push_back(" ");
                }
                // Mettre les valeurs dans l'objet enreg
                Enregistrement *enreg = new Enregistrement(atoi(record.at(0).c_str()),record.at(2),record.at(3),record.at(4),record.at(5),record.at(6),record.at(7),atof(record.at(8).c_str()),atof(record.at(9).c_str()),atoi (record.at(10).c_str()),record.at(11),record.at(12),atoi(record.at(13).c_str()), record.at(14),record.at(15),atoi(record.at(1).c_str()));
                //une fois fait, sauvegarder enreg dans resultat
                resultat.push_back(enreg);
            }
        }

        sqlite3_finalize(stmt);
    }
    return resultat;
}

std::vector<Enregistrement> BDD::obtenirDonneesEnregistrement(double latitude,double longitude)
{
   /*char* req = "SELECT * FROM Enregistrements WHERE latitude BETWEEN "+(latitude - 0.00005)+" AND "+(latitude + 0.00005)+" AND longitude BETWEEN "+(longitude - 0.00005)+ " AND " +(latitude + 0.0005);
   return selectData(req);*/
   //Fait appel a la methode plus haut
}

Enregistrement BDD::obtenirDonneesEnregistrement(string aLatitude, string aLongitude)
{
}


std::vector<Enregistrement*>BDD:: sauvegarderDonneesEnregistrement(Enregistrement *enregistrement,string identifiantCollecteur)
{
    monLogger->saveLog("Enregistrements");

    char *zErrMsg = 0;
    int  rc;
    string typeA;
    string typeL;
    string hauteur;
    int ULOR;
    int puissance;
    string  albedo;
    string fluxLum;
    int nbrePhotos;
    char date [6];
    char heure;
    char longitude[10];
    char latitude[10];
    vector<Enregistrement*> leRetour;
    string identifiantE;
    string  agglomeration;
    string  rue;
    string notes;

    enregistrement->getLampadaire(typeL,hauteur,ULOR,albedo);
    enregistrement->getAmpoule(typeA,fluxLum,puissance);
    enregistrement->getGalerie(nbrePhotos);
    enregistrement->getHorodatage(date);
    string laDate=string(date,6);

    enregistrement->getGeolocalisation(latitude,longitude);

    string laLongitude=string(longitude);

    string laLatitude=string(latitude);

    identifiantE = enregistrement->getIdentifiant();

    agglomeration = enregistrement->getAgglomeration();
    rue = enregistrement->getRue();
    notes=enregistrement->getNotes();

    sqlite3_stmt *stmt;
    const char *pzTest;

    std::string sql="INSERT INTO Enregistrements(power,albedo,flux,buboid,lamp,streetlight,height,latitude,longitude,nbimages,town,street,ulor,date,notes) VALUES (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
	rc = sqlite3_prepare(db, sql.c_str(), sql.length(), &stmt, &pzTest);

    if( rc == SQLITE_OK )
    {
        // bind the value
	sqlite3_bind_int(stmt, 1, puissance);
	sqlite3_bind_text(stmt, 2, albedo.c_str(),albedo.length(), 0);
	sqlite3_bind_text(stmt, 3, fluxLum.c_str(),fluxLum.length(),0);
	sqlite3_bind_text(stmt, 4, identifiantCollecteur.c_str(), identifiantCollecteur.length(), 0);
	sqlite3_bind_text(stmt, 5, typeA.c_str(), typeA.length(), 0);
	sqlite3_bind_text(stmt, 6, typeL.c_str(), typeL.length(), 0);
	sqlite3_bind_text(stmt,7, hauteur.c_str(),hauteur.length(), 0);
	sqlite3_bind_text(stmt, 8,laLatitude.c_str(), laLatitude.length(), 0);
	sqlite3_bind_text(stmt, 9,laLongitude.c_str(), laLongitude.length(), 0);
	sqlite3_bind_int(stmt, 10, nbrePhotos);
	sqlite3_bind_text(stmt, 11 ,agglomeration.c_str(), agglomeration.length(), 0);
	sqlite3_bind_text(stmt, 12 ,rue.c_str(), rue.length(), 0);
	sqlite3_bind_int(stmt, 13, ULOR);
	sqlite3_bind_text(stmt,14, laDate.c_str(), laDate.length(), 0);
	sqlite3_bind_text(stmt,15, notes.c_str(), notes.length(), 0);

	sqlite3_step(stmt);
	monLogger->saveLog("Insertion effectue");

    }
    sqlite3_finalize(stmt);


    std:: string req = "SELECT * FROM Enregistrements ORDER BY ID DESC LIMIT 1 ";

	sqlite3_stmt *state;                     //|objet d'instruction preparer
	const char *pztest;
    vector<Enregistrement*>resultat;
    int rc2 = sqlite3_prepare_v2(db,req.c_str(), req.length() , &state, &pztest);			//|prepare la requete

    if(!rc2)
    {
        int nbColonne=sqlite3_column_count(state);
            //recuperation d'une ligne
            rc2 = sqlite3_step(state);

            if(rc2 == SQLITE_ROW)
            {
                vector<string> record;

                    for(int i = 0; i < nbColonne; i++)
                    {
                        if (sqlite3_column_text(state, i))
                        record.push_back((char*)sqlite3_column_text(state,i));
                        else record.push_back(" ");
                    }

                // Mettre les valeurs dans l'objet enreg
                Enregistrement *enreg = new Enregistrement(atoi(record.at(0).c_str()),record.at(2),record.at(3),record.at(4),record.at(5),record.at(6),record.at(7),atof(record.at(8).c_str()),atof(record.at(9).c_str()),atoi (record.at(10).c_str()),record.at(11),record.at(12),atoi(record.at(13).c_str()), record.at(14),record.at(15),atoi(record.at(1).c_str()));
                //une fois fait, sauvegarder enreg dans resultat

                resultat.push_back(enreg);
            }

        sqlite3_finalize(state);
    }

    return resultat;
}



void BDD::modifierEnregistrement(int id, int puissance, string albedo, string fluxLum, string idRaspbery, string typeAmpoule, string typeLampadaire, string hauteur, double latitude, double longitude, int nbImages, string agglo, string rue , int ulor, string date, string notes)
{

 sqlite3_stmt *stmt;
    const char *pzTest;


std :: string sql = "UPDATE Enregistrements SET puissance=?, albedo=?, fluxlum=? , buboid=?, amptype=?, lamptype=?, hauteur=?, latitude=?, longitude=?, nbimages=?, agglomeration=?, rue=?, ulor=?, date=?, notes=? where id=?";

cout<<"test requete"<<endl;     
int rc = sqlite3_prepare(db,sql.c_str(), sql.length(), &stmt, &pzTest);
cout<<"test rc : "<< rc<<endl;
if ( rc == SQLITE_OK) {
cout<<"test1"<<endl;
sqlite3_bind_int(stmt,1,puissance);
        sqlite3_bind_text(stmt,2,albedo.c_str(),albedo.length(),0);
        sqlite3_bind_text(stmt,3,fluxLum.c_str(),fluxLum.length(),0);
        sqlite3_bind_text(stmt,4,idRaspbery.c_str(),idRaspbery.length(),0);
        sqlite3_bind_text(stmt,5,typeAmpoule.c_str(),typeAmpoule.length(),0);
        sqlite3_bind_text(stmt,6,typeLampadaire.c_str(),typeLampadaire.length(),0);
        sqlite3_bind_text(stmt,7,hauteur.c_str(),hauteur.length(),0);
        sqlite3_bind_double(stmt,8,latitude);
        sqlite3_bind_double(stmt,9,longitude);
        sqlite3_bind_int(stmt,10,nbImages);
        sqlite3_bind_text(stmt,11,agglo.c_str(),agglo.length(),0);
        sqlite3_bind_text(stmt,12,rue.c_str(),rue.length(),0);
        sqlite3_bind_int(stmt,13,ulor);
        sqlite3_bind_text(stmt,14,date.c_str(),date.length(),0);
        sqlite3_bind_text(stmt,15,notes.c_str(),notes.length(),0);
        sqlite3_bind_int(stmt,16,id);
        cout<<"ok"<<endl;

        rc =sqlite3_step(stmt);
        cout<<"test step:"<<rc<<endl;
        rc=sqlite3_finalize(stmt);
        cout<<"test finalize :"<<rc<<endl;
        cout << "Insertion effectuée1"<<endl;

      }
        sqlite3_close(db);
}

void BDD::supprimerEnregistrement(int id)
{
    std::string requetesql = "DELETE FROM Enregistrements WHERE id=?";
    sqlite3_stmt *stmt;
    const char *pzTest;
    string mon_fichier = "/home/pi/testBDD.txt";
    ofstream fichier(mon_fichier.c_str(),  ios::out | ios::app  );
    int rc = sqlite3_prepare(db,requetesql.c_str(), requetesql.length(), &stmt, &pzTest);
    fichier<<"after DELETE sqlite3_prepare "<<sqlite3_errmsg(db)<<endl;
    if ( rc == SQLITE_OK) 
    {
        sqlite3_bind_int(stmt,1,id);
        rc =sqlite3_step(stmt);
        fichier<<"after DELETE step "<<sqlite3_errmsg(db)<<endl;
        rc=sqlite3_finalize(stmt);
        fichier<<"after DELETE sqlite3_finalize "<<sqlite3_errmsg(db)<<endl;
    }
    sqlite3_close(db);
}
