//Project: Racquetball
//Joo Yun (Rosa) Kim

#include <iostream>
#include "Racquetball.h"
#include <time.h>
#include <cmath>
#include <unistd.h>
#include <cstdlib>

#define PI 3.14

using namespace std;

int main() 
{
	int wd, ht;
	cout << "              ####### RACQUETBALL #######              " << endl;
	cout << endl;
	cout << "Enter desired size of court in integers (width height): ";		//recommended size: 50 30
	cin >> wd;
	cin >> ht;
	game c(wd, ht);
	c.run();
	return 0;
}
