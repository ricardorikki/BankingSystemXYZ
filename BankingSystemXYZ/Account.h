#pragma once
#include <string>
class Account
{
private:
	
	int  AccountNumber = 0;
	char AccountName[50];
	int  deposit = 0;
	char type;
	int  Balance = 0;

public:

	void create_account();
	void show_account() const;
	void modify();
	void dep(int);
	void draw(int);
	void report() const;
	int retacno() const;
	int retdeposit() const;
	char rettype() const;

	void setBalance(int);
	int getBalance();
	

	void write_account();
	void display_sp(int);
	void modify_account(int);
	void delete_account(int);
	void display_all();
	void deposit_withdraw(int, int);

};

