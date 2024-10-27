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
double calcAMonthsPayment(double principle, double interest, int months);
void calcTheAmortizeSchedule(double balance, double interest, int months, int currentPeriod);

int main()
{
	cout << "Zachary Seeley -- Lab 1 - Functions and Recursion Program Assignment" << endl << endl;

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
void collectInputs(double& principle, double& rate, int& term)
{


	cout << "Inputs collected" << endl << endl;
}

//calculate monthly payment
double calcAMonthsPayment(double principle, double interest, int months)
{
	cout << "Months Payment Calculated" << endl << endl;

	return 0.0;
}

//Directly recursive function to display 
void calcTheAmortizeSchedule(double balance, double interest, int months, int currentPeriod)
{

}