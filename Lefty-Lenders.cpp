//==========================================================
//
// Title:      Lefty Lenders
// Author:     Abir Ahmed
// Date:       4 November 2019
// Description:
//   This C++ console application determines the number of 
// months to repay a car loan.  It prompts for and gets from
// the user the car loan amount in the range $1,000-5,000.  
// It then prompts for and gets from the user the monthly 
// payment in the range $100-500.  It then prompts for and 
// gets from the user the annual interest rate in the range 
// 2-5%.  The application converts the rate to a monthly 
// rate.  It then shows the loan being repaid and keeps 
// track of the number of months it takes to do so.
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

int main()
{

  // Declare constants
  const int COLFMT = 16;

  // Declare variables
  double amount;
  double payment;
  double rate;
  double balance;
  double interest;
  double principal;
  int month;

  // Format real numbers
  cout << fixed << setprecision(2);

  // Show application header
  cout << "Welcome to Lefty Lenders" << endl;
  cout << "-------------------------" << endl << endl;

  // Loop to prompt for and get amount
  cout << "Enter the car loan amount ($1K-5K): ";
  cin >> amount;
  while (amount < 1000 || amount > 5000)
  {
    cout << "ERROR: '" << amount 
      << "' is an invalid loan amount." << endl;
    cout << "Enter the car loan amount ($1K-5K): ";
    cin >> amount;
  }

  // Loop to prompt for and get term
  cout << "Enter the monthly payment ($100-500): ";
  cin >> payment;
  while (payment < 100 || payment > 500)
  {
    cout << "ERROR: '" << payment 
      << "' is an invalid payment." << endl;
    cout << "Enter the monthly payment ($100-500): ";
    cin >> payment;
  }

  // Loop to prompt for and get interest rate
  cout << "Enter the annual interest rate (2-5%): ";
  cin >> rate;
  while (rate < 2 || rate > 5)
  {
    cout << "ERROR: '" << rate 
      << "' is an invalid annual interest rate." << endl;
    cout << "Enter the annual interest rate (2-5%): ";
    cin >> rate;
  }
  rate = rate / 12 / 100;

  // Show column headers
  cout << endl;
  cout 
    << right << setw(COLFMT) << "Month"
    << right << setw(COLFMT) << "Balance($)"
    << right << setw(COLFMT) << "Payment($)"
    << right << setw(COLFMT) << "Interest($)"
    << right << setw(COLFMT) << "Principal($)"
    << endl;

  // Loop to pay loan
  balance = amount;
  month = 0;
  while (balance > 0)
  {

    // Increment month
    month = month + 1;

    // Update balance
    interest = balance * rate;
    principal = payment - interest;
    balance = balance - principal;

    // Show column headers
    cout 
      << right << setw(COLFMT) << month
      << right << setw(COLFMT) << balance
      << right << setw(COLFMT) << payment
      << right << setw(COLFMT) << interest
      << right << setw(COLFMT) << principal
      << endl;

  }

  // Show months to repay
  cout << "\nMonths to repay loan: " << month << endl;

  // Show application close
  cout << "\nEnd of Lefty Lenders" << endl;

}
