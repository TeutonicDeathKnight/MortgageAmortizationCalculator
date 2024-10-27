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
void collectInputs(double& principle, double& rate, int& term);
double calcAMonthsPayment(double principle, double rate, int months);

int main()
{
	cout << "Zachary Seeley -- Lab 1 - Functions and Recursion Program Assignment" << endl << endl;

	//variable declarations
	double principle, rate, payment;
	int term, months;

	collectInputs(principle, rate, term);

	months = term * 12;

	payment = calcAMonthsPayment(principle, rate, months);

	//Closing program statements
	system("pause");
	return 0;
}

//function definitions

//prompt user for input and validate input is correct
void collectInputs(double& principle, double& rate, int& term)
{
	cout << "Inputs collected" << endl << endl;
}

//calculate monthly payment
double calcAMonthsPayment(double principle, double rate, int months)
{
	cout << "Months Payment Calculated" << endl << endl;

	return 0.0;
}