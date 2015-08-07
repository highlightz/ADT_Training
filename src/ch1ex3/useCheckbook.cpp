// useCheckbook.cpp - A program for using the Checkbook class
#include <iostream>
#include <iomanip>
#include "checkbook.h"

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int menu( );

const int CHECK = 1, DEPOSIT = 2, BALANCE = 3, QUIT = 4;

int main(  )
{
	Checkbook cb;
	float initialBalance;
	cout << "Enter the initial balance: $";
	cin >> initialBalance;
	cb.setBalance( initialBalance );

	cout << fixed << showpoint << setprecision( 2 );

	int choice = menu(  );
	while ( QUIT != choice )
	{
		if ( CHECK == choice )
		{
			cout << "Enter the amount you want to check: " << endl;
			float checkAmount;
			cin >> checkAmount;
			if ( cb.writeCheck( checkAmount ) )
				cout << "Accepted!" << endl;
			else
				cout << "Unaccepted!" << endl; 
		}
		else if ( DEPOSIT == choice )
		{
			cout << "Enter the amount you want to deposit: " << endl;
			float depositAmount;
			cin >> depositAmount;
			cb.deposit( depositAmount );
			cout << "Successful!" << endl;
		}
		else if ( BALANCE == choice )
		{
			cout << "Current balance is: " << cb.getBalance(  ) << endl;
		}
		else
		{
			cout << "Error choice!" << endl;
		}
		choice = menu(  );
	}

	return 0;
}
int menu(  )
{
	int choice;

	cout << endl;
	cout << "Enter a number between 1 and 4: " << endl;
	cout << "1 for check." << endl;
	cout << "2 for deposit." << endl;
	cout << "3 for balance look-up." << endl;
	cout << "4 to quit." << endl;
	cin >> choice;

	return choice;
}
