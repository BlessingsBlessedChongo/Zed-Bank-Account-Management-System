#include<iostream>
#include<string>
#include<vector>

using namespace std;

//Define BankAccount class
class BankAccount {
private:
	string accountNumber;
	string accountHolderName;
	double balance;
public:
	//constructor
	BankAccount(string accountNumber, string accountHolderName, double initialBalance) {
		this->accountNumber = accountNumber;
		this->accountHolderName = accountHolderName;
		this->balance = initialBalance;
	}
	//gettor Methods
	string getAccountNumber() {
		return accountNumber;
	}
	string getAccountHolderName() {
		return accountHolderName;
	}
	double getBalance() {
		return balance;
	}
	//Deposit Money
	void deposit(double amount) {
		balance += amount;
		cout << "Deposit successful. New balance: K" << balance << endl;
	}
	//Withdraw Money
	void withdraw(double amount) {
		if (amount > balance) {
			cout << "Insufficient funds." << endl;
		}
		else {
			balance -= amount;
			cout << "Withdraw successful. New balance: K" << balance << endl;
		}
	}
	//Display Account details
	void displayDetails() {
		cout << "\n\nAccount Number: " << accountNumber << endl;
		cout << "Account Holder Name: " << accountHolderName << endl;
		cout << "Balance: K" << balance << endl;
	}
	
};
//Define BankAccountManager class
class BankAccountManager {
private:
	vector<BankAccount> accounts;
public:
	//Add new account
	void addAccount(string accountNumber, string accountHolder, double initialBalance) {
		BankAccount newAccount(accountNumber, accountHolder, initialBalance);
		accounts.push_back(newAccount);
	}
	//Find account by account Number
	BankAccount* findAccount(string accountNumber) {
		for (auto& account : accounts) {
			if (account.getAccountNumber() == accountNumber) {
				return &account;
			}
		}
		return nullptr;
	}
	//Display all accounts
	void displayAllAccounts() {
		for (auto& account : accounts) {
			account.displayDetails();
			cout << endl;
		}
	}
};
int main() {
	BankAccountManager manager;
	//Menudriven interface
	while (true) {
		cout << "\n\nZed Bank Account Manager" << endl;
		cout << "1. Create new account" << endl;
		cout << "2. Deposit money" << endl;
		cout << "3. Withdraw Money" << endl;
		cout << "4. Display account details" << endl;
		cout << "5. Display all accounts" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		
		int choice;
		cin >> choice;
		

		if (choice == 1) {
			string accountNumber, accountHolderName;
			double initialBalance;
			cout << "\n\nEnter account number: ";
			cin >> accountNumber;
			cout << "Enter account holder name: ";
			cin >> accountHolderName;
			cout << "Enter initial balance: K";
			cin >> initialBalance;

			manager.addAccount(accountNumber, accountHolderName, initialBalance);
			cout << "account successfully created. ";
			
		}
		else if (choice == 2) {


			string accountNumber;
			double amount;
			cout << "\n\nEnter account number: ";
			cin >> accountNumber;
			cout << "Enter amount to deposit: K";
			cin >> amount;

			BankAccount* account = manager.findAccount(accountNumber);
			if (account) {
				account->deposit(amount);
			}
			else {
				cout << "Account not found." << endl;
			}
		}
		else if (choice == 3) {


			string accountNumber;
			double amount;
			cout << "\n\nEnter the account number: ";
			cin >> accountNumber;
			cout << "Enter amount to withdraw: K";
			cin >> amount;
			BankAccount* account = manager.findAccount(accountNumber);
			if (account) {
				account->withdraw(amount);
			}
			else {
				cout << "Account not found." << endl;
			}
		}
		else if (choice == 4) {


			string accountNumber;
			cout << "\n\nEnter account number: ";
			cin >> accountNumber;
			BankAccount* account = manager.findAccount(accountNumber);
			if (account) {
				account->displayDetails();
			}
			else {
				cout << "Account not found." << endl;
			}
		}
		else if (choice == 5) {

		
			manager.displayAllAccounts();
		}
		else if (choice == 6) {

			return 0;
		}else{
		
			cout << "Invalid choice. Please try again." << endl;
		}

		
	}
	return 0;
}