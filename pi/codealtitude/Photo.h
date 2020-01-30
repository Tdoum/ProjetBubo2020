#include <exception>
#include <string>
#include "cgicc/CgiDefs.h"
#include "cgicc/Cgicc.h"
using namespace std;

#ifndef __Photo_h__
#define __Photo_h__

// #include "Galerie.h"

	class Photo
	{
		/**
		 * Les photos sont identifiées par leur nom qui est dérivé de l’identifiant unique de l’enregistrement auquel elles sont associées (avec un numéro incrémenté pour les distinguer le cas échéant)
		 */
		private: string _identifiant;
				 string photoRepertoire;
			     string IMG_EXTENSION = ".jpg";

		public: void uploadPhoto(string aPhoto, string aIdentifiant);
		public:
			Photo(std::string l);
			~Photo();
			bool supprime(std::string nom);
			bool ajoute(cgicc::FormFile fichier, std::string enregistrement);

		private:

			int getNbPhoto(std::string directory);

		public: void setIdentifiant(string aIdentifiant);

		public: string getIdentifiant();
	};

#endif
