//Main.cpp
#include "Menu.h"
#include<iostream>
using namespace std;


int main() {
	setlocale(LC_ALL, "ru");
	cout << "Kondilyabrova Veronika Daniilovna\nGroup 414" << endl;
	cout << "Control work ¹1\nVariant 10\n\nDevelop a program for compiling a list of clients. \nIt is necessary to develop a class for the specified subject area. \nTo implement data access using the Set, Get, Show methods.\nClient: last name, first name, patronymic, address, phone number, card number, bank account number. \nCreate an array of objects. To realize the possibility of obtaining: a list of clients in alphabetical order, \na list of clients whose card number is in a given interval.\n" << endl;
	MenuMain();
	return 0;
}