#include "Account.h"
#include <iostream>
#include<fstream>
#include<cctype>
#include<iomanip>


using namespace std;


void Account::create_account()
{
	system("CLS");
	cout << "\n\t\t\tEnter the Account No. : ";
	cin >> AccountNumber;
	cout << "\n\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(AccountName, 50);
	cout << "\n\t\t\tEnter Type of the Account (C/S) : ";
	cin >> type;
	type = toupper(type);
	cout << "\n\t\t\tEnter The Initial amount : $";
	//cin>>deposit;
	while (!(cin >> deposit) || (deposit < 1000))
	{
		cout << "\n\t\t\tError: The amount entered is less than $1000.";
		cout << "\n\t\t\tPlease enter $1000 / Greater: $";
		cin.clear();
		cin.ignore(123, '\n');
	}


	cout << "\n\n\t\t\tAccount Created..";
}

void Account::show_account() const
{
	cout << "\n\t\t\tAccount No. : " << AccountNumber;
	cout << "\n\t\t\tAccount Holder Name : ";
	cout << AccountName;
	cout << "\n\t\t\tType of Account : " << type;
	cout << "\n\t\t\tBalance amount : " << deposit;
}


void Account::modify()
{
	cout << "\n\t\t\tAccount No. : " << AccountNumber;
	cout << "\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(AccountName, 50);
	cout << "\n\t\t\tModify Type of Account : ";
	cin >> type;
	type = toupper(type);
	cout << "\n\t\t\tModify Balance amount : ";
	cin >> deposit;
}


void Account::dep(int x)
{
	deposit += x;
}

void Account::draw(int x)
{
	deposit -= x;
}

void Account::report() const
{
	cout << AccountNumber << setw(10) << " " << AccountName << setw(10) << " " << type << setw(6) << deposit << endl;
}

int Account::retacno() const
{
	return AccountNumber;
}

int Account::retdeposit() const
{
	return deposit;
}

char Account::rettype() const
{
	return type;
}

void Account::setBalance(int bal)
{
	Balance = bal;
}

long Account::getBalance()
{
	return Balance;
}



void Account::write_account()
{
	Account ac;
	ofstream outFile;
	outFile.open("account.dat", ios::binary | ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char*> (&ac), sizeof(Account));
	outFile.close();
}


//****************************DISPLAYING BALANCE ENQUIRY*****************************************************

void Account::display_sp(int n)
{
	Account ac;
	bool flag = false;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\n\t\t\tBALANCE DETAILS\n";
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(Account)))
	{
		if (ac.retacno() == n)
		{
			ac.show_account();
			flag = true;
		}
	}
	inFile.close();
	if (flag == false)
		cout << "\n\n\t\t\tAccount number does not exist";
}


//****************************MODIFY ACCOUNTS FILES TO BE SAVED*****************************************************

void Account::modify_account(int n)
{
	bool found = false;
	Account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&ac), sizeof(Account));
		if (ac.retacno() == n)
		{
			ac.show_account();
			cout << "\n\n\t\t\tEnter The New Details of account" << endl;
			ac.modify();
			int pos = (-1) * static_cast<int>(sizeof(Account));
			File.seekp(pos, ios::cur); 
			File.write(reinterpret_cast<char*> (&ac), sizeof(Account));
			cout << "\n\n\t\t\tRecord Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n\t\t\tRecord Not Found ";
}



//****************************DELETE ACCOUNTS IN THE SYSTEM USING SAVED FILES*****************************************************

void Account::delete_account(int n)
{
	Account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat", ios::binary);
	inFile.seekg(0, ios::beg);
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(Account)))
	{
		if (ac.retacno() != n)
		{
			outFile.write(reinterpret_cast<char*> (&ac), sizeof(Account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat", "account.dat");
	cout << "\n\nRecord Deleted ..";
}


//*************************DISPLAY ALL THE SAVED ACCOUNTS IN THE SYSTEM***********************************************

void Account::display_all()
{
	system("CLS");
	Account ac;
	ifstream inFile;
	inFile.open("account.dat", ios::binary);
	if (!inFile)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	cout << "\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout << "====================================================\n";
	cout << "A/c no.      NAME           Type  Balance\n";
	cout << "====================================================\n";
	while (inFile.read(reinterpret_cast<char*> (&ac), sizeof(Account)))
	{
		ac.report();
	}
	inFile.close();
}

//****************************WITHDRAW STATEMENTS USING THE SAVED FILES*****************************************************

void Account::deposit_withdraw(int n, int option)
{
	int amt;
	bool found = false;
	Account ac;
	fstream File;
	File.open("account.dat", ios::binary | ios::in | ios::out);
	if (!File)
	{
		cout << "File could not be open !! Press any Key...";
		return;
	}
	while (!File.eof() && found == false)
	{
		File.read(reinterpret_cast<char*> (&ac), sizeof(Account));
		if (ac.retacno() == n)
		{
			ac.show_account();
			if (option == 1)
			{
				cout << "\n\n\t\t\tTO DEPOSITSS AMOUNT";
				cout << "\n\n\t\t\tEnter The amount to be deposited: $";
				cin >> amt;
				ac.dep(amt);
			}
			if (option == 2)
			{
				cout << "\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout << "\n\n\t\t\tEnter The amount to be withdraw: $";
				cin >> amt;
				int bal = ac.retdeposit() - amt;
				if (bal < 0)
					cout << "Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos = (-1) * static_cast<int>(sizeof(ac));
			File.seekp(pos, ios::cur);
			File.write(reinterpret_cast<char*> (&ac), sizeof(Account));
			cout << "\n\n\t\t\tRecord Updated";
			found = true;
		}
	}
	File.close();
	if (found == false)
		cout << "\n\n\t\t\tRecord Not Found ";

}