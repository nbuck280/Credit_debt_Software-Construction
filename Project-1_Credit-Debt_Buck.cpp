//Nate Buck
//Project-1_Credit-Debt_Buck.cpp
// Compile: g++ Project-1_Credit-Debt_Buck.cpp
//execute: ./a.out

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int loan = 0;
    int yearlyRate = 0;
    float monthlyPayment = 0;
    
    //Enter loan amount and put to loan variable
    cout << "Loan Amount: ";
    cin >> loan;

    //Enter interest rate and put to yearlyRate variable
    cout << "Interest Rate (% per year): ";
    cin >> yearlyRate;

    //Enter the amount for the monthly payments and put to monthlyPayment variable
    cout << "Monthly Payments: ";
    cin >> monthlyPayment;

    //Top of the table
    cout << left << "**********************************************************\n";
    cout << left << "\tAmortization Table\n";
    cout << left << "**********************************************************\n";
    printf("%-7s %-9s %-12s %-7s %-10s %-10s\n",
           "Month", "Balance", "Payment", "Rate", "Interest", "Principal");
    //Beginning of variables to print as the program runs
    float balance = loan;
    float rate = (yearlyRate / 12.00) / 100.0;
    float totalInterest = 0;
    float principal = 0;
    int month = 0;
    float interest = 0;

//Formatting output
cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);

//While loop that runs until the balance is 0
while (balance > 0){
    if (month ==0){
        //What to do for the first month
        
        printf("%-7i $%-8.2f %-12s %-7s %-10s %-10s\n",
           month, balance, "N/A", "N/A", "N/A", "N/A");
        month++;
    }
    else {
        //What to do for the rest of the months
        interest = balance * rate;
        balance = balance + interest - monthlyPayment;
        if (balance < 0){
            //If balance goes below zero, add that negative value to monthlyPayment to figure out how much you actually paid
            //Set balance to 0
            monthlyPayment = monthlyPayment + balance;
            balance = 0;
        }
        principal = monthlyPayment - interest;
        totalInterest = totalInterest + interest;
        printf("%-7i $%-8.2f $%-12.2f %-7.2f $%-10.2f $%-10.2f\n",
           month, balance, monthlyPayment, (rate*100), interest, principal);
        month++;
    }
    }
    //Bottom of the table and extra info at the bottom
    cout << left << "**********************************************************\n\n";
    cout << "It takes " + to_string(month-1) + " months to pay off the loan.\n";
    cout <<  "Total interest paid is: $" << totalInterest << "\n";
    return 0;
}
