#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>

#include <random>

using namespace std;

int main ()
{
	//random_device rd; 
	//mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
	//std::uniform_int_distribution<> dis(1, 6);
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