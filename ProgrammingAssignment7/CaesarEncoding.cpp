/*****************************************************************************************
*  Program Name: CaesarEncoding.cpp
*  Created Date: 12/5/18
*  Created By: Shawn Ruby
*  Purpose: encodes or decodes a message
*  Acknowledgements: None
*****************************************************************************************/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;

/*****************************************************************************************
*  Class Name:  SecretMessage()
*  Parameters:  none   
*  Return Value: none
*  Purpose: contains all code. Runs the program and asks the user if they would like to encode or decode a message. This shifts the letters based on the input of the user
*****************************************************************************************/

class SecretMessage
{
protected:
	/* Variable for the times the characters will be shfited */
	int CharShift;

	/* variable for the message to be encoded or decoded */
	string Message;

	/* variable for the decision by the user to encode, decode or exit */
	string decision;

	/* variable that asks the user if they want to repeat the program to run again */
	string repeat;

	/* variable for the length of the string message */
	int length;

public:
	/* function that will display the instructions and calculate the decision */
	void showstring()
	{
		/* instruction opening message and asks the user for encode, decode or exit */
		cout << "Welcome to the Caesar Encoder/Decoder!\nWhat would you like to do?\n\nEncode.\nDecode."
			"\nExit.\n\n";
		cin >> decision;

		/* based on the user input, it will convert the whole string to upper case letters */
		transform(decision.begin(), decision.end(), decision.begin(), toupper);

		/* if the decision is encode it will run the encode function */
		if (decision == "ENCODE")
		{
			Encode();
		}
		/* if the decision is decode it will run the decode function */
		else if (decision == "DECODE")
		{
			Decode();
		}
		/* if the decision is exit then it will exit the program */
		else if (decision == "EXIT")
		{
			exit(0);
		}

		/* input validation that will keep asking the user for an appropriate response. If the user enters appropriate response it goes to the appropriate function and breaks the loop */
		while (decision != "ENCODE" && decision != "DECODE" && decision != "EXIT")
		{
			cout << "\nThat is an incorrect response! Please type:\nEncode.\nDecode.\nExit. ";
			cin >> decision;
			if (decision == "ENCODE")
			{
				Encode();
				break;
			}
			else if (decision == "DECODE")
			{
				Decode();
				break;
			}
			else if (decision == "EXIT")
			{
				exit(0);
			}
		}
	}

	/* function that will encode the message by shifting the letters */
	char Encode()
	{
		/* asks the user for the message to encode and ends the message with '~' */
		cout << "\nWhat is the message you would like to encode? (end the message with '~') ";
		getline(cin, Message, '~');

		/* variable that is assigned to the length of the message */
		length = (int)Message.length();

		/* asks the user for how many times they want to shift the letters */
		cout << "\nWhat is the number of times that you want to shift the letters? ";
		cin >> CharShift;

		/* Cout statement that says the encoded message is */
		cout << "\nThe encoded message is ";

		/* loops throughout every character of the message */
		for (int i = 0; i < length; i++)
		{
			/* checks if each character is a character */
			if (isalpha(Message.at(i)))
			{
				/* loops through each time the character is shifted */
				for (int j = 0; j < CharShift; j++)
				{
					/* if the character is lowercase z it will go to lowercase a */
					if (Message[i] >= 122)
					{
						Message[i] = 97;
					}
					/* if the character is Uppercase Z it will go to uppercase A */
					else if (Message[i] >= 90 && Message[i] < 97)
					{
						Message[i] = 65;
					}
					/* else it will just shift to the right*/
					else
					{
						Message[i] += 1;
					}
				}
				/* once it has shifted the letter, it will display each letter */
				cout << Message[i];
			}
			/* if the character is not a letter then it is just put back down */
			else
			{
				cout << Message[i];
			}
		}
		/* asks the user if they would like to go again */
		cout << "\n\nWould you like to go again? (y/n) ";
		cin >> repeat;

		/* if they put in y or Y it will clear the screen and repeat the program */
		if (repeat == "y" || repeat == "Y")
		{
			system("CLS");
			showstring();
		}
		/* if n or N it will close the program */
		else if (repeat == "n" || repeat == "N")
		{
			exit(0);
		}
		/* input validation that will keep asking the user to input y, Y, n or N */
		while (repeat != "y" && repeat != "Y" && repeat != "N" && repeat != "n")
		{
			cout << "\nSorry, that is not a correct response! Please try again. (y/n) ";
			cin >> repeat;

			if (repeat == "y" || repeat == "Y")
			{
				system("CLS");
				showstring();
			}
			else if (repeat == "n" || repeat == "N")
			{
				exit(0);
			}
		}
	}
	char Decode()
	{
		/* asks the user for the message to encode and ends the message with '~' */
		cout << "\nWhat is the message you would like to Decode? (end the message with '~') ";
		getline(cin, Message, '~');

		/* variable that is assigned to the length of the message */
		length = (int)Message.length();

		/* asks the user for how many times they want to shift the letters */
		cout << "\nWhat is the number of times that you want to shift the letters? ";
		cin >> CharShift;
		cout << "\nThe Decoded message is ";

		/* loops throughout every character of the message */
		for (int i = 0; i < length; i++)
		{
			/* checks if each character is a character */
			if (isalpha(Message.at(i)))
			{
				/* loops through each time the character is shifted */
				for (int j = 0; j < CharShift; j++)
				{
					/* if the character is lowercase a it will go to lowercase z */
					if (Message[i] <= 97 && Message[i] > 90)
					{
						Message[i] = 122;
					}
					/* if the character is Uppercase A it will go to uppercase Z */
					else if (Message[i] <= 65)
					{
						Message[i] = 90;
					}
					/* else it will just shift to the left */
					else
					{
						Message[i] -= 1;
					}
				}
				/* once it has shifted the letter, it will display each letter */
				cout << Message[i];
			}
			/* if the character is not a letter then it is just put back down */
			else
			{
				cout << Message[i];
			}
		}
		/* asks the user if they would like to go again */
		cout << "\n\nWould you like to go again? (y/n) ";
		cin >> repeat;

		/* if they put in y or Y it will clear the screen and repeat the program */
		if (repeat == "y" || repeat == "Y")
		{
			system("CLS");
			showstring();
		}
		/* if n or N it will close the program */
		else if (repeat == "n" || repeat == "N")
		{
			exit(0);
		}
		/* input validation that will keep asking the user to input y, Y, n or N */
		while (repeat != "y" && repeat != "Y" && repeat != "N" && repeat != "n")
		{
			cout << "\nSorry, that is not a correct response! Please try again. (y/n) ";
			cin >> repeat;

			if (repeat == "y" || repeat == "Y")
			{
				system("CLS");
				showstring();
			}
			else if (repeat == "n" || repeat == "N")
			{
				exit(0);
			}
		}
	}
};

/*****************************************************************************************
*  function Name:  main()
*  Parameters:  none
*  Return Value: none
*  Purpose: starting position before going to the class 
*****************************************************************************************/

int main()
{
	/* assigns an object for the class */
	SecretMessage s1;

	/* calls the class for the object */
	s1.showstring();

	/* pauses the program before finishing*/
	system("pause");
}

