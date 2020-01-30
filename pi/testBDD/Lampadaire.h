#include <string>
using namespace std;

#ifndef __Lampadaire_h__
#define __Lampadaire_h__

// #include "Enregistrement.h"


	class Lampadaire
	{
		private: string _type;
		private: string _hauteur;
		private: int _uLOR;
		private: string _albedo;


		public: void setType(string aType);

		public: string getType();

		public: void setHauteur(string aHauteur);

		public: string getHauteur();

		public: void setULOR(int aULOR);

		public: int getULOR();

		public: void setAlbedo(string aAlbedo);

		public: string getAlbedo();

		public : Lampadaire();
	};

#endif
