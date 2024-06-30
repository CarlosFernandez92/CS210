#pragma once
#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include <cstdlib>
using namespace std;
class itemSearch
{
public:
	itemSearch();
	itemSearch(string inputFileName, string outputFileName);
	void setInputFileName(string fileName);
	void setOutputFileName(string fileName);
	void readFile();
	void writeFile();
	void printMap();
	void printMenu();
	int getMenuOption();
	void executeMenuOption(int choice);
	void searchItem();
	void run();
	void printHistogram();

private:
	map<string, int> itemFrequency;
	string inputFileName;
	string outputFileName;
};