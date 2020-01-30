#ifndef DEF_GPS
#define DEF_GPS

#include <vector>
#include <algorithm>

#define MAUVAISETRAME -1
#define ALERTE -2
#define ERREURCHECKSUM -3
#define ECHECCAPTURE -4
#define ERREURACCESPORT -5
#define ERREURCONFIGURATION -6


class GPS
{

public :
	GPS();
	int lire ();
	int extraireRMC(std::vector<char> &trameRMC);
	int extraire(std::vector<char> &trame,std::vector<char> messages, std::vector<char> GPYYY);
	std::vector<char> getSalve();
private :
	std::vector<char> salve;
	bool verifierChecksum (std::vector<char> trameRMC);

};


#endif