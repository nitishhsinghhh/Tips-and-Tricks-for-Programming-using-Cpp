#include<iostream>
using namespace std;

// Define the base class Account.
class Account {
public:
	// Constructor that initializes the balance.
	Account(double d) { _balance = d; }

	// Virtual destructor.
	virtual ~Account() {}

	// Virtual function to get the balance.
	virtual double GetBalance() { return _balance; }

	// Virtual function to print the balance.
	virtual void PrintBalance() { cerr << "Error. Balance not available for base type." << endl; }
private:
	double _balance; // Balance of the account.
};

// Define the derived class CheckingAccount.
class CheckingAccount : public Account {
public:
	// Constructor that calls the base constructor.
	CheckingAccount(double d) : Account(d) {}

	// Override the PrintBalance function to print the account type and balance.
	void PrintBalance() { cout << "Checking account balance: " << GetBalance() << endl; }
};

// Define the derived class SavingsAccount.
class SavingsAccount : public Account {
public:
	// Constructor that calls the base constructor.
	SavingsAccount(double d) : Account(d) {}

	// Override the PrintBalance function to print the account type and balance.
	void PrintBalance() { cout << "Savings account balance: " << GetBalance() << endl; }
};

// To call PrintBalance in the base class, use code such as the following
void main() {
	CheckingAccount *pChecking = new CheckingAccount(100.00);
	pChecking->Account::PrintBalance();  //  Explicit qualification.
	Account *pAccount = pChecking;  // Call Account::PrintBalance
	pAccount->Account::PrintBalance();   //  Explicit qualification.
}
