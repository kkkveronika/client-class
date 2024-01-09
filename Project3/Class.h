//Class.h
#pragma once

#include<iostream>
#include <string>
using namespace std;

class Client {
private:
	string Surename = "";
	string Name = "";
	string Second_name = "";
	string City = "";
	string Street = "";
	int House = 0;
	int Number_card = 0;
	int Numb_bank_account = 0;
	int Phone_numb = 0;


public:

	Client();

	Client(string Surename, string Name, string Second_name, string City, string Street, int House, //
		int Number_card, int Numb_bank_account, int Phone_numb);

	string getSurename();
	void setSurename(string Surename);

	string getName();
	void setName(string Name);

	string getSecondName();
	void setSecondName(string Second_name);

	string getCity();
	void setCity(string City);

	string getStreet();
	void setStreet(string Street);

	int getHouse();
	void setHouse(int House);

	int getNumberCard();
	void setNumberCard(int Number_card);

	int getNumbBankAccount();
	void setNumbBankAccount(int Numb_bank_account);

	int getPhoneNumb();
	void setPhoneNumb(int Phone_numb);

	void Show(int i);

};
