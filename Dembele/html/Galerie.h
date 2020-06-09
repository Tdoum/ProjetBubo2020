#include <exception>
#include <string>
#include <vector>
using namespace std;

#ifndef __Galerie_h__
#define __Galerie_h__

// #include "Enregistrement.h"
#include "Photo.h"

	class Galerie
	{
		private: int _nbrePhotos;

		public: std::vector< Photo*> photos;

		public: void ajouterPhotos(string aPhotos, int aNbre, string aIdentifiant);

		private: void creerRepertoire(string aIdentifant);

		public: void setNbrePhotos(int aNbrePhotos);

		public: int getNbrePhotos();
		
	};


#endif
