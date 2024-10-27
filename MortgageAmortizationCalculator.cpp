// MortgageAmortizationCalculator.cpp -- Calculate monthly payment for loans and display amortization schedule
//CSIS 112-<D02_202440>
//<Citations if necessary> -- citations are required
//  for any references you used (outside of your book, 
//  the website associated with your book, or references
//  provided in class/Canvas).

//Include statements
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

//function prototypes
void collectInputs(double& principal, double& rate, int& term);
double calcAMonthsPayment(double principal, double interest, int months);
void calcTheAmortizeSchedule(double balance, double interest, int months, int currentPeriod);

void clearInputStream();

int main()
{
	cout << "Zachary Seeley -- Lab 1 - Recursion" << endl << endl << endl;

	//variable declarations
	double principal, rate, payment, balance, interest;
	int term, months, currentPeriod = 0;

	collectInputs(principal, rate, term);

	months = term * 12;
	interest = rate / 12;
	balance = principal;

	payment = calcAMonthsPayment(principal, interest, months);

	cout << "Zachary Seeley -- Lab 1 - Recursion" << endl << endl
		<< "Loan Application Information and Amortization Schedule" << endl << endl << endl;

	calcTheAmortizeSchedule(balance, interest, months, currentPeriod);

	//Closing program statements
	system("pause");
	return 0;
}

//function definitions

//prompt user for input and validate input is correct
void collectInputs(double& principal, double& rate, int& term)
{
	bool validPrincipal = false;
	bool validRate = false;
	bool validTerm = false;

	// prompt user for valid principal
	// reprompt user for valid principal if invalid input
	while (validPrincipal != true)
	{
		cout << left << setw(45) << "Principal (between 100000 & 250000):";
		cin >> principal;

		if (cin.fail() || (principal < 100000 || principal > 250000))
			cout << endl << endl << "ERROR: Please enter a valid numeric value between 100000 and 250000." << endl << endl;
		else
			validPrincipal = true;

		clearInputStream();
	}

	// prompt user for valid interest rate
	// reprompt user for valid interst rate if invalid input
	while (validRate != true)
	{
		cout << left << setw(45) << "Annual Interest Rate (between 1.0 & 10.0):";
		cin >> rate;

		if (cin.fail() || (rate < 1.0 || rate > 10.0))
			cout << endl << endl << "ERROR: Please enter a valid decimal number between 1.0 and 10.0" << endl << endl;
		else
			validRate = true;

		clearInputStream();
	}

	// prompt user vor valid loan term length
	// reprompt user for valid interest rate if invalid input
	while (validTerm != true)
	{
		cout << left << setw(45) << "Loan Term in Years (20, 25, 30, or 40):";
		cin >> term;

		if (cin.fail() || (term != 20 && term != 25 && term != 30 && term != 40))
			cout << endl << endl << "ERROR: Please enter a valid term leng as 20, 25, 30, or 40." << endl << endl;
		else
			validTerm = true;

		clearInputStream();
	}
	
	system("pause");
	system("cls");
}

//calculate monthly payment
double calcAMonthsPayment(double principal, double interest, int months)
{
	cout << "Months Payment Calculated" << endl << endl;

	return 0.0;
}

//Directly recursive function to display 
void calcTheAmortizeSchedule(double balance, double interest, int months, int currentPeriod)
{
	

	cout << "Amortization Schedule Displayed" << endl << endl;
}

//Clear input stream
void clearInputStream()
{
	//clear 
	cin.clear();
	//ignore rest of line determining max length of line until the newline character appears
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}