#include <iostream>		
#include <thread>	 
#include <chrono>
#include <conio.h>

using namespace std;			// cout, endl
using namespace this_thread;	// sleep_for
using namespace chrono;			// seconds, milliseconds

enum emotion
{
	calm = 0,
	alert = 1,
	agitated = 2,
	suprised = 3,
	happy = 4,
	angry = 5
};

bool getEscKey();
int emotionEvent(int emotionSwitch);
void NPC_Switch_Statement_Example(int emotionSwitch);
void printCommands();

int main()
{
	bool program_running = true;
	int emotionSwitch = 0;

	cout << "Starting Finite State Machine. Press ESC key to close." << endl << endl;
	printCommands();
	cout << "NPC is calm" << endl;
	do {

		/*

		Write your code here for the finite state machine example

		*/
		NPC_Switch_Statement_Example(emotionSwitch);
		// Sleep the current thread for 1000 milliseconds. Can be repalce with seconds(1)
		//sleep_for(milliseconds(100));

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

void NPC_Switch_Statement_Example(int emotionSwitch)
{
	 emotion NPC_emotion;

	 NPC_emotion = calm;
	 emotionSwitch = emotionEvent(emotionSwitch);

	 switch (emotionSwitch)
	 {
	 case 1:
		 NPC_emotion = alert;
		 cout << "NPC is alert" << endl;
		 break;
	 case 2: case 4: case 8:
		 NPC_emotion = calm;
		 cout << "NPC is calm" << endl;
		 break;
	 case 3:
		 NPC_emotion = agitated;
		 cout << "NPC is agitated" << endl;
		 break;
	 case 5:
		 NPC_emotion = suprised;
		 cout << "NPC is suprised" << endl;
		 break;
	 case 6:
		 NPC_emotion = happy;
		 cout << "NPC is happy" << endl;
		 break;
	 case 7:
		 NPC_emotion = angry;
		 cout << "NPC is angry" << endl;
		 break;
	 }


}

int emotionEvent(int emotionSwitch)
{
	bool isAlone = true;
	if (_kbhit())
	{
		char input_char = _getch();
		
		//See table here http://www.asciitable.com/

		if (input_char == 51)//Num 3
		{
			isAlone = false;
			//NPC sees another NPC
			emotionSwitch = 3;
			return emotionSwitch;	
		}
		if (input_char == 52 && emotionSwitch == 3)//Num 4
		{
			//NPC is friendly
			emotionSwitch = 4;
			return emotionSwitch;
		}
		if (input_char == 53 && emotionSwitch == 3)//Num 5
		{
			//NPC is aggressive
			emotionSwitch = 5;
			return emotionSwitch;

			if (input_char == 53)//Num 5
			{
				//NPC attacks
				emotionSwitch = 7;
				return emotionSwitch;

			}
		}
		if (input_char == 54 && emotionSwitch == 3)//Num 6
		{
			//NPC is funny
			emotionSwitch = 6;
			return emotionSwitch;
		}

		if (input_char == 55 && emotionSwitch == 3)//Num 7
		{
			//NPC goes away
			isAlone = true;
			emotionSwitch = 8;
			return emotionSwitch;
		}

		if (input_char == 49 && isAlone)//Num 1
		{
			//NPC Hears Noise alone
			emotionSwitch = 1;
			return emotionSwitch;
		}
		else if (input_char == 50)//Num 2
		{
			//Noise Stops
			emotionSwitch = 2;
			return emotionSwitch;
		}
	}
}

void printCommands()
{
	cout << "This is what can be done to the NPC:" << endl;
	cout << "Num Key 1: The NPC will hear a noise and become alerted" << endl;
	cout << "Num Key 2: The noise will stop and calm the NPC" << endl;
	cout << "Num Key 3: NPC sees another NPC and becomes aggitated" << endl;
	cout << "Num Key 4: The other NPC is friendly" << endl;
	cout << "Num Key 5: The other NPC is aggressive" << endl;
	cout << "Num Key 6: The other NPC is funny" << endl;
	cout << "Num Key 7: The other NPC attacks" << endl;
	cout << "Num Key 8: The other NPC goes away" << endl << endl << endl;
}