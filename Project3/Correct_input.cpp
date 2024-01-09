//Correct_input.cpp
#include <iostream>
#include<string>
#include "Correct_input.h"
using namespace std;

string GetString() {
	int count = 0;
	int flag = 0;
	string Enter;
	while (flag != 1) {
		cin >> Enter;
		char Symbol;
		int len = (int)Enter.length();
		for (int i = 0; i < len; i++) {
			Symbol = Enter[i];
			if (!((Symbol >= 'A' && Symbol <= 'Z') || (Symbol >= 'a' && Symbol <= 'z'))) {
				count += 1;
			}
		}
		if (count > 0) {
			cout << "Error. Try again." << endl;
			cin.clear();
			cin.sync();
			cin.ignore(INT_MAX, '\n');
			count = 0;
		}
		else {
			flag = 1;
		}
	}
	return Enter;
}

int GetInt() {
	int input;
	cin >> input;
	while (!(input >= 1)) {
		cout << "Error. Try again." << endl;
		cin.clear();
		cin.sync();
		cin.ignore(INT_MAX, '\n');
		cin >> input;
	}
	return input;
}

int GetSaveChoice() {
	int input;
	cin >> input;
	while (!(input >= 1 && input <= 2)) {
		cout << "Error. Try again." << endl;
		cin.clear();
		cin.sync();
		cin.ignore(INT_MAX, '\n');
		cin >> input;
	}
	return input;
}

bool GetBool() {
	bool input;
	cin >> input;
	while (!(input == 0 || input ==1)) {
		cout << "Error. Try again." << endl;
		cin.clear();
		cin.sync();
		cin.ignore(INT_MAX, '\n');
		cin >> input;
	}
	return input;
}

//unsigned long long int getlongint() {
//	unsigned long long int input;
//	cin >> input;
//	while (!(input >= 0)) {
//		cout << "ошибка! напишите правильно." << endl;
//		cin.clear();
//		cin.sync();
//		cin.ignore(ullong_max, '\n');
//		cin >> input;
//	}
//	return input;
//}