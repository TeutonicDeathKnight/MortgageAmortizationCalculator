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
//bool validPrincipal(double _value);

int main()
{
	cout << "Zachary Seeley -- Lab 1 - Recursion" << endl << endl;

	//variable declarations
	double principal, rate, payment, balance, interest;
	int term, months, currentPeriod = 0;

	collectInputs(principal, rate, term);

	months = term * 12;
	interest = rate / 12;
	balance = principal;

	payment = calcAMonthsPayment(principal, interest, months);

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

	cout << "Loan Application Information and Amortization Schedule" << endl << endl << endl;

	// prompt user for valid principal
	// reprompt user for valid principal if invalid input
	while (validPrincipal != true)
	{
		cout << left << setw(45) << "Principal (between 100000 & 250000):";
		cin >> principal;

		if (cin.fail())
		{
			cout << endl << endl << "ERROR: Please enter a valid numeric value between 100000 and 250000." << endl << endl;
		}
		else if (principal < 100000 || principal > 250000)
		{
			cout << endl << endl << "ERROR: Please enter a single whole number between 100000 and 250000." << endl << endl;
		}
		else
		{
			cout << endl;
			validPrincipal = true;
		}

		clearInputStream();
	}

	

	cout << "Inputs collected" << endl << endl;
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

}

//Clear input stream
void clearInputStream()
{
	//clear 
	cin.clear();
	//ignore rest of line determining max length of line until the newline character appears
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//bool validPrincipal(double _value)
//{
//
//}