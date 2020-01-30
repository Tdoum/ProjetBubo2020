#include <exception>
#include <string>
using namespace std;

#ifndef __Ampoule_h__
#define __Ampoule_h__

// #include "Enregistrement.h"

	class Ampoule
	{
		private: string _type;
		private: string _intensiteLumineuse;
		private: int _puissance;

		public: float mesurerILux();

		public: void setType(string aType);

		public: string getType();

		public: void setIntensiteLumineuse(string aIntensiteLumineuse);

		public: string getIntensiteLumineuse();

		public: void setPuissance(int aPuissance);

		public: int getPuissance();
	};


#endif
