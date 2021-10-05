

#include <iostream>
#include "Account.h"

using namespace std;

int main()
{
	Account acc;


	//system("pause>0");*/


	char ch;
	int num;
	do
	{
		system("CLS");
		cout << "\n\n\t\t\t\t======================\n";
		cout << "\t\t\t\tXYZ BANKING SYSTEM";
		cout << "\n\t\t\t\t======================\n";

		cout << "\t\t\t\t    ::MAIN MENU::\n";
		cout << "\n\t\t\t\t1. NEW ACCOUNT";
		cout << "\n\t\t\t\t2. DEPOSIT AMOUNT";
		cout << "\n\t\t\t\t3. WITHDRAW AMOUNT";
		cout << "\n\t\t\t\t4. BALANCE ENQUIRY";
		cout << "\n\t\t\t\t5. ALL ACCOUNT HOLDER LIST";
		cout << "\n\t\t\t\t6. CLOSE AN ACCOUNT";
		cout << "\n\t\t\t\t7. MODIFY AN ACCOUNT";
		cout << "\n\t\t\t\t8. EXIT";
		cout << "\n\n\t\t\t\tSelect Your Option (1-8): ";
		cin >> ch;

		switch (ch)
		{
		case '1':
			acc.write_account();
			break;
		case '2':
			system("CLS");
			cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
			acc.deposit_withdraw(num, 1);
			break;
		case '3':
			system("CLS");
			cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
			acc.deposit_withdraw(num, 2);
			break;
		case '4':
			system("CLS");
			cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
			acc.display_sp(num);
			break;
		case '5':
			acc.display_all();
			break;
		case '6':
			system("CLS");
			cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
			acc.delete_account(num);
			break;
		case '7':
			system("CLS");
			cout << "\n\n\t\t\tEnter The account No. : "; cin >> num;
			acc.modify_account(num);
			break;
		case '8':
			system("CLS");
			cout << "\n\n\tThank you for using XYZ Bank";
			cout << "\n\n\t\tGOOD BYE!";
			break;
		default:cout << "\a";
		}
		cin.ignore();
		cin.get();
	} while (ch != '8');
	return 0;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
