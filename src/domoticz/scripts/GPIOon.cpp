#include <iostream>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "GPIOClass.h"

using namespace std;

int main (void)
{


	string inputstate;
	GPIOClass* gpio4 = new GPIOClass("4"); //create new GPIO object to be attached to  GPIO4
	gpio4->export_gpio(); //export GPIO4

	cout << " GPIO pins exported" << endl;

	gpio4->setdir_gpio("in"); //GPIO4 set to output

	cout << " Set GPIO pin directions" << endl;


    	gpio4->setval_gpio("1"); // turn LED ON

   	cout << " Turning it on" << endl;

	cout << "Exiting....." << endl;
	return 0;
}
