/* 
Name: Carlos Fernadez
Date: May 23, 2024
Class: CS-210
*/

#include <iostream>
#include <iomanip>
#include<string>
using namespace std;

void printClockBorder()
{
	// Function to declare borders for our clock
	// For loop for spacing
	for (int i = 0; i < 16; ++i)
	{
		cout << " ";
	}
	// For loop for the 12 hour clock border
	for (int i = 0; i < 27; ++i)
	{
		cout << "*";
	}
	// For loop for spacing
	for (int i = 0; i < 5; ++i)
	{
		cout << " ";
	}
	// For loop for the 24 hour clock 
	for (int i = 0; i < 27; ++i)
	{
		cout << "*";
	}
	cout << endl;
}

// Function to output to both clocks
void printClocks(int hours, int minutes, int seconds)
{
	// Create attributes for the 12 hour clock
	// Hour conversion
	int hourConv;
	// Minute conversion
	int minConv;
	// Second conversion
	int secConv;
	string amPm = "AM"; // AM PM

	// Convert 12 hour to 24 hour.
	if (hours == 0)
	{
		hourConv = 12;
	}
	else if (hours == 12)
	{
		hourConv = hours;
		amPm = "PM";
	}
	else if (hours > 12)
	{
		hourConv = hours - 12;
		amPm = "PM";
	}
	else
	{
		hourConv = hours;
	}


	// Create Clock titles
	cout << "\t\t * \t" << "12 Hour Clock";
	cout << "\t *";
	cout << "\t *" << "\t24 Hour Clock";
	cout << "\t *" << endl;

	// 12 Hour Clock
	cout << "\t\t* \t";
	cout << setw(2) << setfill('0') << hourConv << ":";
	cout << setw(2) << minutes << ":";
	cout << setw(2) << seconds;
	cout << " " << amPm;
	cout << "\t *";

	// 24 Hour Clock
	cout << "\t*" << "\t   ";
	cout << setw(2) << setfill('0') << hours << ":";
	cout << setw(2) << minutes << ":";
	cout << setw(2) << seconds;
	cout << "\t  *" << endl;
}

// Create a function to get the initial time for the clock
void inputInitialTime(int& setHour, int& setMinute, int& setSecond)
{
	// Hold initial user input
	string inputString;
	// Used for input validation
	string tempString;
	// Valid time toggle used for the while statement in the main function
	bool validTime = false;
	// Used to find the colon separators
	int firstColon;
	int secondColon;
	while (!validTime)
	{
		// Set while statement to get user input.
		cout << "Enter the time in a HH:MM:SS in a 24 hour format: ";
		getline(cin, inputString);
		// Use the colons to create separations for hours, minutes, and seconds
		firstColon = inputString.find(':');
		secondColon = inputString.find(':', firstColon + 1);
		// Attempt to assign and convert correct sections.  Otherwise, ignore.
		try
		{
			// Set each interger by using the sections of the string separated by the colons.
			setHour = stoi(inputString.substr(0, firstColon));
			setMinute = stoi(inputString.substr(firstColon + 1, secondColon));
			setSecond = stoi(inputString.substr(secondColon + 1, inputString.size() - 1));
		}
		catch (const std::exception&)
		{
			// Unused
		}
		
		// Fail if the string is too short.
		if (inputString.size() != 8)
		{
			cout << "This is not a valid time." << endl;
			!validTime;
		}

		// Check for valid interger amounts in 3 else if statements.
		else if (setHour < 0 || setHour > 23)
		{
			cout << "This is not a valid time." << endl;
			!validTime;
		}
		else if (setMinute < 0 || setMinute > 59)
		{
			cout << "This is not a valid time." << endl;
			!validTime;
		}
		else if (setSecond < 0 || setSecond > 59)
		{
			cout << "This is not a valid time." << endl;
			!validTime;
		}

		// Confirm time is valid by setting bool to true.
		else
		{
			validTime = true;
		}
	}
}

// Create menu options for users
void printMenu()
{
	cout << endl;
	cout << "*********************************" << endl;
	cout << "* 1-Add One Hour\t\t*" << endl;
	cout << "* 2-Add One Minute\t\t*" << endl;
	cout << "* 3-Add One Second\t\t*" << endl;
	cout << "* 4-Exit\t\t\t*" << endl;
	cout << "*********************************" << endl;
	cout << endl;
}

// Create process for interaction with the user menu
void processInput(int& userChoice, int& setHour, int& setMinute, int&setSecond) {
	// Prompt user for options input
	cout << "Select option (1-4): ";
	// Verify user input
	if (!(cin >> userChoice))
	{ 
		cin.clear();
		// Ensure that non-interger inputs are ignored
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
			userChoice = 0;
	}
	// Utilize switch statements based on user input
	switch (userChoice) {
	case 1:
		cout << "1 hour added" << endl;
		if (setHour < 23) 
		{
			++setHour;
		}
		else 
		{
			setHour = 00;
		}
		break;
	case 2:
		cout << "1 minute added" << endl;
		if (setMinute < 59) 
		{ 
			++setMinute;
		}
		else 
		{
			setMinute = 00;
			// If Else statement to change the hour properly
			if (setHour < 23)
			{
				++setHour;
			}
			else
			{
				setHour == 00;
			}
		}
		break;
	case 3:
		if (setSecond < 59)
		{
			++setSecond;
		}
		else 
		{
			setSecond = 00;
			// If Else statement to change minute properly
			if (setMinute < 59)
			{
				++setMinute;
			}
			else
			{
				setMinute == 00;
			}

		}
		break;
	case 4:
		cout << "Goodbye!" << endl;
		break;
	default:
		cout << "Invalid choice. Enter a number between 1-4..." << endl;
		cin.clear();
		break;
	}
}
int main() 
{
	
	int userChoice = 0;
	int setHour = 0;
	int setMinute = 0;
	int setSecond = 0;
	inputInitialTime(setHour, setMinute, setSecond);
	while (userChoice != 4)
	{
		printClockBorder();
		printClocks(setHour, setMinute, setSecond);
		printClockBorder();
		printMenu();
		processInput(userChoice, setHour, setMinute, setSecond);
	}
	return 0;
}