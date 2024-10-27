// MortgageAmortizationCalculator.cpp -- Calculate monthly payment for loans and display amortization schedule
//CSIS 112-<D02_202440>
//Input validation logic derived from coding examples in assignment instructions
//  Input validation logic on lines 61-72, 76-90, 94-105

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
void calcTheAmortizeSchedule(double balance, double payment, double interest, int months, int currentPeriod);
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

	calcTheAmortizeSchedule(balance, payment, interest, months, currentPeriod);

	cout << endl;

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
		{
			rate = rate / 100; // convert to percentage
			validRate = true;
		}

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
	
	cout << endl;
	system("pause");
	system("cls");
}

//calculate monthly payment using given equation
double calcAMonthsPayment(double principal, double interest, int months)
{
	double payment, innerCalc;

	innerCalc = pow((1 + interest), months);

	payment = principal * ((interest * innerCalc) / (innerCalc - 1));

	return payment;
}

//Directly recursive function to calculate and display amortization schedule
void calcTheAmortizeSchedule(double balance, double payment, double interest, int months, int currentPeriod)
{
	double interestPayment, principalPayment;

	//If it is the first period, display the headers and starting balance
	if (currentPeriod == 0)
	{
		cout << left << setw(45) << "Principle:" << balance << endl;
		cout << left << setw(45) << "Life of loan:" << months / 12 << " years" << endl;
		cout << left << setw(45) << "Annual interest rate:" << interest * 1200 << '%' << endl;
		cout << fixed << setprecision(2) << left << setw(45) << "Monthly payment" << payment << endl << endl;

		cout << right << setw(10) << "Payment" << setw(10) << "Amount"
			<< setw(10) << "Interest" << setw(11) << "Principle" << setw(12) << "Balance" << endl
			<< setw(53) << balance << endl;
	}
	
	//increment period to current period
	currentPeriod++;

	//calculate interest and principle payments
	interestPayment = round(balance * interest * 100) / 100;
	principalPayment = payment - interestPayment;

	//If principle payment is greater than the default principle payment
	//make the principle payment the balance and add balance and interest payment to determine total payment
	if (principalPayment > balance)
	{
		principalPayment = balance;
		payment = principalPayment + interestPayment;
	}

	//determine balance output value
	balance = balance - principalPayment;

	//output details about period
	cout << setw(10) << currentPeriod << setw(10) << payment << setw(10) << interestPayment
		<< setw(11) << principalPayment << setw(12) << balance << endl;

	//if current peiod is not the final period, call self function to calculate and display next line
	if (currentPeriod != months)
		calcTheAmortizeSchedule(balance, payment, interest, months, currentPeriod);
}

//Clear input stream
void clearInputStream()
{
	//clear 
	cin.clear();
	//ignore rest of line determining max length of line until the newline character appears
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}