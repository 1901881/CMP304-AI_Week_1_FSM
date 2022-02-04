#include <iostream>		
#include <thread>	 
#include <chrono>
#include <conio.h>

using namespace std;			// cout, endl
using namespace this_thread;	// sleep_for
using namespace chrono;			// seconds, milliseconds

bool getEscKey();

int main()
{
	bool program_running = true;

	cout << "Starting Finite State Machine. Press ESC key to close." << endl;

	do {

		/*

		Write your code here for the finite state machine example

		*/

		// Sleep the current thread for 1000 milliseconds. Can be repalce with seconds(1)
		sleep_for(milliseconds(1000));

	} while (!getEscKey());

	cout << "Ending Finite State Machine" << endl;

	return 0;
}

bool getEscKey()
{
	bool isKeyPressed = false;
	if (_kbhit())
	{
		char input_char = _getch();

		// Check for ESC key. See table here http://www.asciitable.com/
		if (input_char == 27)
		{
			isKeyPressed = true;
		}
		return isKeyPressed;
	}
}