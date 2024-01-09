//Class.cpp
#include "Class.h"

Client::Client() {
};


Client::Client(string Surename, string Name, string Second_name,//
	string City, string Street, int House, int Number_card, //
	int Numb_bank_account, int Phone_numb) {
	this->Surename = Surename;
	this->Name = Name;
	this->Second_name = Second_name;
	this->City = City;
	this->Street = Street;
	this->House = House;
	this->Number_card = Number_card;
	this->Numb_bank_account = Numb_bank_account;
	this->Phone_numb = Phone_numb;
}


string Client::getSurename()
{
	return Surename;
}

void Client::setSurename(string surename)
{
	this->Surename =surename;
}

string Client::getName()
{
	return Name;
}

void Client::setName(string name)
{
	this->Name = name;
}

string Client::getSecondName()
{
	return Second_name;
}

void Client::setSecondName(string second_name)
{
	this->Second_name = second_name;
}

string Client::getCity()
{
	return City;
}

void Client::setCity(string city)
{
	this->City = city;
}

string Client::getStreet()
{
	return Street;
}

void Client::setStreet(string street)
{
	this->Street = street;
}

int Client::getHouse()
{
	return House;
}

void Client::setHouse(int house)
{
	this->House = house;
}
int Client::getNumberCard()
{
	return Number_card;
}

void Client::setNumberCard(int number_card)
{
	this->Number_card = number_card;
}

int Client::getNumbBankAccount()
{
	return Numb_bank_account;
}

void Client::setNumbBankAccount(int numb_bank_account)
{
	this->Numb_bank_account = numb_bank_account;
}

int Client::getPhoneNumb()
{
	return Phone_numb;
}

void Client::setPhoneNumb(int phone_numb)
{
	this->Phone_numb = phone_numb;
}


void Client::Show(int i) {
	cout<< "Client ¹ "<< i+1 << ":\n" << "Full name: "<< getSurename() <<" "<< getName() <<" "<< getSecondName() << "\nAdress  " << getCity() << ", " << getStreet() << //
		" " << getHouse() << "\nCard number:  " << getNumberCard() << "\nBank account number:  " << getNumbBankAccount() << "\nPhone number  " << getPhoneNumb() << endl;
}
