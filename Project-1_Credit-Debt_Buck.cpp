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
    
    cout << "Loan Amount: ";
    cin >> loan;

    cout << "Interest Rate (% per year): ";
    cin >> yearlyRate;

    cout << "Monthly Payments: ";
    cin >> monthlyPayment;

    cout << left << "**********************************************************\n";
    cout << left << "\tAmortization Table\n";
    cout << left << "**********************************************************\n";
    cout << left << "Month\tBalance \tPayment\tRate\tInterest\tPrincipal\n";
     
    float balance = loan;
    float rate = (yearlyRate / 12.00) / 100.0;
    float totalInterest = 0;
    float principal = 0;
    int month = 0;
    float interest = 0;

cout.setf(ios::fixed);
cout.setf(ios::showpoint);
cout.precision(2);
while (balance > 0){
    if (month ==0){
        cout << left << month << "\t$" << balance << " \t" << "N/A" << "\t" << "N/A" << "\t" << "N/A" << "\t" << "N/A" << endl;
        month++;
    }
    else {
        interest = balance * rate;
        balance = balance + interest - monthlyPayment;
        if (balance < 0){
            monthlyPayment = monthlyPayment + balance;
            balance = 0;
        }
        principal = monthlyPayment - interest;
        totalInterest = totalInterest + interest;
        cout << left << month << "\t$" << balance << " \t$" << monthlyPayment << "\t" << (rate*100) << "\t$" << interest << "\t$" << principal << endl;
        month++;
    }
    }
    cout << left << "**********************************************************\n\n";
    cout << "It takes " + to_string(month-1) + " months to pay off the loan.\n";
    cout <<  "Total interest paid is: $" << totalInterest << "\n";
    return 0;
}
