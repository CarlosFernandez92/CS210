/*
Carlos Fernandez
June 10th, 2024
CS210
Project 2
*/


#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int main()
{
	// Create the variables for the program
	double initialInvestment;
	double monthlyDeposit;
	double annualInterest;
	int numberOfYears;
	// Declare constants - in this case, the months per year
	const int monthsInYear = 12;
	// Get inputted values from the user.
	cout << "Welcome to the Airgead Banking Investment Calculator!" << endl;
	cout << "Enter initial investment amount (in dollars): ";
	cin >> initialInvestment;
	cout << "Enter monthly deposit amount (in dollars): ";
	cin >> monthlyDeposit;
	cout << "Enter annual interest rate (as a percentage): ";
	cin >> annualInterest;
	cout << "Enter number of years to invest: ";
	cin >> numberOfYears;
	// Open a file for output
	ofstream outputFile("InvestmentSummary.txt");
	if (!outputFile)
	{
		cerr << "Error opening output file." << endl;
		return 1;
	}    
	// Create the header bar for the output txt file
	outputFile << setw(11) << left << "Year" << " | " << setw(19) << left << "Opening Balance" << " | " <<
		setw(19) << left << "Deposited Amount" << " | " << setw(18) << left << "Interest Earned" << " | " << setw(19) << left << "Closing Balance" << endl;
	// Update the current balance variable with the initial investment
	double currentBalance = initialInvestment;
	double openingBalance = currentBalance;
	double closingBalance = currentBalance;
	// Loop through each year    
	for (int year = 1; year <= numberOfYears; year++)
	{        
		// Initialize variables for this year
		double yearEndInterest = 0;
		// Loop through each month in this year
		for (int month = 1; month <= monthsInYear; month++)
		{
			openingBalance = currentBalance;
			// Calculate monthly interest
			double monthlyInterestRate = annualInterest / monthsInYear / 100;
			double monthEndInterest = currentBalance * monthlyInterestRate;
			// Calculate closing balance
			currentBalance = currentBalance + monthlyDeposit + monthEndInterest;
			// Accumulate year-end interest
			yearEndInterest = yearEndInterest + monthEndInterest;
			closingBalance = currentBalance;
			
		}
		// Print year-end summary to the output file
		outputFile << fixed << setprecision(2);
		//outputFile << year << " \t " << currentBalance << " \t " << monthlyDeposit * monthsInYear << " \t " << yearEndInterest << " \t " << currentBalance << endl;
		outputFile << setw(11) << left << year << " | " << setw(19) << left << openingBalance << " | " <<
			setw(19) << left << monthlyDeposit * monthsInYear << " | " << setw(18) << left << yearEndInterest << " | " << setw(19) << left << closingBalance << endl;
	}    
	// Close the output file
	outputFile.close();
	// Display a message to the user
	cout << "Results have been saved to InvestmentSummary.txt." << endl;
	return 0;
}