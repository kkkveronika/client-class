//Test_comparison.cpp
#include "Test_comparison.h"
#include"Function.h"

bool TestComparison(Client* Work_client, Client* Result_client, int size, int number) {
	bool test_name;
	if ((Work_client[0].getSurename() == Result_client[0].getSurename()) && (Work_client[0].getName() == Result_client[0].getName())
		&& (Work_client[0].getSecondName() == Result_client[0].getSecondName()) && (Work_client[0].getCity() == Result_client[0].getCity())
		&& (Work_client[0].getStreet() == Result_client[0].getStreet()) && (Work_client[0].getHouse() == Result_client[0].getHouse())
		&& (Work_client[0].getNumberCard() == Result_client[0].getNumberCard()) && (Work_client[0].getNumbBankAccount() == Result_client[0].getNumbBankAccount())
		&& (Work_client[0].getPhoneNumb() == Result_client[0].getPhoneNumb()) && (Work_client[1].getSurename() == Result_client[1].getSurename()) && (Work_client[1].getName() == Result_client[1].getName())
		&& (Work_client[1].getSecondName() == Result_client[1].getSecondName()) && (Work_client[1].getCity() == Result_client[1].getCity())
		&& (Work_client[1].getStreet() == Result_client[1].getStreet()) && (Work_client[1].getHouse() == Result_client[1].getHouse())
		&& (Work_client[1].getNumberCard() == Result_client[1].getNumberCard()) && (Work_client[1].getNumbBankAccount() == Result_client[1].getNumbBankAccount())
		&& (Work_client[1].getPhoneNumb() == Result_client[1].getPhoneNumb())	&& (Work_client[2].getSurename() == Result_client[2].getSurename()) && (Work_client[2].getName() == Result_client[2].getName())
		&& (Work_client[2].getSecondName() == Result_client[2].getSecondName()) && (Work_client[2].getCity() == Result_client[2].getCity())
		&& (Work_client[2].getStreet() == Result_client[2].getStreet()) && (Work_client[2].getHouse() == Result_client[2].getHouse())
		&& (Work_client[2].getNumberCard() == Result_client[2].getNumberCard()) && (Work_client[2].getNumbBankAccount() == Result_client[2].getNumbBankAccount())
		&& (Work_client[2].getPhoneNumb() == Result_client[2].getPhoneNumb()))
		{
		test_name = true;
	}
	else {
		test_name = false;
		cout << endl << "Test ¹" << number << " failed." << endl << endl;
		cout << "The result of the work:" << endl;
		for (int i = 0; i < size; i++) {
			Work_client[i].Show(i);
		}
		cout << endl << "Expected result:" << endl;
		for (int i = 0; i < size; i++) {
			Result_client[i].Show(i);
		}
	}
	return test_name;
}


bool TestComparisonByCount(Client* Work_client, Client* Result_client, int Result_size, int Work_size, int number) {
	bool test_numb_card=false;
	if (Work_size == Result_size) {
		bool flag = true;
		for (int i = 0; i < Result_size; i++) {
			if ((Work_client[i].getSurename() != Result_client[i].getSurename()) || (Work_client[i].getName() != Result_client[i].getName())
				|| (Work_client[i].getSecondName() != Result_client[i].getSecondName()) || (Work_client[i].getCity() != Result_client[i].getCity())
				|| (Work_client[i].getStreet() != Result_client[i].getStreet()) || (Work_client[i].getHouse() != Result_client[i].getHouse())
				|| (Work_client[i].getNumberCard() != Result_client[i].getNumberCard()) || (Work_client[i].getNumbBankAccount() != Result_client[i].getNumbBankAccount())
				|| (Work_client[i].getPhoneNumb() != Result_client[i].getPhoneNumb()))
			{
				flag = false;
			}
		}
		if (flag == true) {
			test_numb_card = true;
		}
		else {
			test_numb_card = false;
			cout << endl << "Test ¹" << number << " failed." << endl << endl;
			cout << "The result of the work:" << endl;
			for (int i = 0; i < Work_size; i++) {
				Work_client[i].Show(i);
			}
			cout << endl << "Expected result:" << endl;
			for (int i = 0; i < Result_size; i++) {
				Result_client[i].Show(i);
			}
		}
	}
	if (Work_size != Result_size) {
		cout << endl << "Test ¹" << number << " failed." << endl << endl;
		cout << "The result of the work:" << endl;
		for (int i = 0; i < Work_size; i++) {
			Work_client[i].Show(i);
		}
		cout << endl << "Expected result:" << endl;
		for (int i = 0; i < Result_size; i++) {
			Result_client[i].Show(i);
		}
	}
	return test_numb_card;
}