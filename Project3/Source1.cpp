/*
Carlos Fernandez
June 20th, 2024
CS210
Project 3
*/


#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

// Create class to creat a map for storing information on item frequency
class itemSearch
{
private:
	map<string, int> itemFrequency;
	string inputFileName = "CS210_Project_Three_Input_File.txt";
	string outputFileName = "frequency.dat";

public:
	string item;
	int frequency;
	// Create function to read the input file
	void readInputFile()
	{
		ifstream inputFile(inputFileName);

		// Form a While statement to identify frequencies of each item
		while (inputFile >> item >> frequency)
		{
			itemFrequency[item] = frequency;
		}
		inputFile.close();
	}
	
	// Create a function for writing the information into the output file
	void writeOutputFile()
	{
		ofstream outputFile(outputFileName);
		for (auto item : itemFrequency)
		{
			outputFile << item.first << " " << item.second << endl;
		}
		outputFile.close();
	}

	// Create function to search out items
	void searchItem()
	{
		cout << "Enter the item you want to search for: ";
		cin >> item;
		// If else statement to read the item name and find if it has a quantity
		if (itemFrequency.count(item))
		{
			cout << "There are " << itemFrequency[item] << " " << item << "(s) found." << endl;
		}
		else
		{
			cout << "There are no " << item << "s found." << endl;
		}
	}

	// Create a function to print a list of included items
	void printList()
	{
		cout << "Item List:" << endl;
		for (auto item : itemFrequency)
		{
			cout << item.first << " " << item.second << endl;
		}
	}

	// Create a function to create the histogram of item frequency
	void printHistogram()
	{
		cout << "Item Frequency Histogram:" << endl;
		for (auto item : itemFrequency)
		{
			cout << item.first << " ";
			for (int i = 0; i < item.second; i++)
			{
				cout << "X";
			}
			cout << endl;
		}
	}
};

int main()
{
	itemSearch itemSearch;

	int choice;
	do 
	{
		cout << "\nMenu:\n";
		cout << "1. Search for an item\n";
		cout << "2. Show the item list with frequency\n";
		cout << "3. Show the item frequency histogram\n";
		cout << "4. Exit Program\n";
		cout << "\nPlease input your selection: ";
		cin  >> choice;

		switch (choice)
		{
		case 1:
			itemSearch.searchItem();
			break;

		case 2:
			itemSearch.printList();
			break;

		case 3:
			itemSearch.printHistogram();
			break;

		case 4:
			cout << "Thank you.  Goodbye...\n";
			break;

		default:
			cout << "Invalid entry.  Please choose from the given options.\n";
		}
	} while (choice != 4);

	return 0;
}