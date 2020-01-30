#include <exception>
using namespace std;

#ifndef __Luxmètre_h__
#define __Luxmètre_h__

#define TSL2561_ADDR 0x39
#define POWER_ON 0x03
#define CONTROL_REGISTER 0x80
#define TIME_REGISTER 0x81
#define TIME_INTEGRATION 0x2
#define CH0_ADDR 0x8C
#define CH1_ADDR 0x8E

class Luxmetre
{
	public:
		float lireLux();
		Luxmetre();
	private:
		int init();
		void reveilleCapteur();
		void setRegistreTemps();
		char* lireCapteur();
		void ecritureSurCapteur(char* buffer);

		int fd;
};


#endif
