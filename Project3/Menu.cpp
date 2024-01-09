//Menu.cpp

#include<fstream>
#include"Menu.h"

int low_limit = {};
int top_limit = {};
int count_sort_card = {};

void MenuMain() {
	int real_count = 0;
	int count_client = {};
	Client* array_client = nullptr;
	bool exit = false;

	while (exit == false) {
		cout << "Testing - 1\nEnter data - 2\nOpen an additional menu to get data - 3\nExit - 4\nChoose: ";
		int user_choice = GetInt();
		switch (user_choice) {
		case(Testing): {
			Test();
		}break;
		case(Input_Menu): {
			array_client = InputMenu(count_client, &real_count);
		}break;
		case(Get_menu): {
			bool flag = CheckExistanceData(array_client, real_count);
			if (flag == true) {
				MenuGet(array_client, real_count);
			}
			else {
				cout << "You dont enter data. Choose menu item '1' or '2'" << endl;
			}
		}break;
		case(Exit): {
			exit = true;
		}break;
		default: {
			cout << "Error. Try again." << endl;
		}break;
		}
	}
	delete[] array_client;
	array_client = nullptr;
}

Client* InputMenu(int &count_client, int *real_count) {
	bool exit = false;
	Client* client = nullptr;
	while (exit == false) {
		int user_choice{};
		cout << "Keyboard input - 1\nInput from file - 2\nContinue - 3\nChoose: ";
		user_choice = GetInt();
		switch (user_choice) {
		case(Input): {
			cout << "Enter the number of clients: ";
			count_client = GetInt();
			client = CreateArray(count_client);
			cout << "Do you want to save? Yes - 1, No - 2: ";
			int save_choice = GetSaveChoice();
			if (save_choice == 1) {
				InFile(client, count_client);
			}
			if (save_choice == 2) {
				break;
			}
		}break;
		case(Of_file): {
			cout << "Enter the number of clients: ";
			count_client = GetInt();
			client = FromFile(count_client, real_count);
		}break;
		case(Continue): {
			bool flag = CheckExistanceData(client, *real_count);
			if (flag == true) {
				exit = true;
			}
			else {
				cout << "You don't enter data. Choose menu item '1' or '2'" << endl;
			}
		}break;
		default: {
			cout << "Error. Try again." << endl;
		}break;
		}
	}
	return client;
}


void MenuGet(Client *client, int count_client) {
	int user_choice = 0;
	bool exit = false;
	while (exit == false) {
		cout << "List of clients in alphabetical order - 1\nList of clients whose card number is in the interval you entered - 2\nList of all clients - 3\nBack - 4\nChoose: ";
		user_choice = GetInt();
		switch (user_choice) {
		case(Sort_by_alphabet): {
			Client* copy_client_name = new Client[count_client];
			for (int i = 0; i < count_client; i++) {
				copy_client_name[i] = client[i];
			}
			copy_client_name = SortByName(copy_client_name, count_client);
			for (int i = 0; i < count_client; i++) {
				copy_client_name[i].Show(i);
			}
			cout << "Do you want to save? Yes - 1, No - 2: ";
			int save_choice = GetSaveChoice();
			if (save_choice == 1) {
				InFile(copy_client_name, count_client);
			}
			if (save_choice == 2) {
				break;
			}
			delete[] copy_client_name;
			copy_client_name = nullptr;
		}break;
		case(Sort_by_numbercard): {
			cout << "Enter the low limit: ";
			cin >> low_limit;
			cout << "Enter the top limit: ";
			cin >> top_limit;
			count_sort_card = FoundCountSortCard(client, count_client, low_limit, top_limit);
			if (count_sort_card > 0) {
				Client* copy_for_sort_numb_card = new Client[count_sort_card];
				copy_for_sort_numb_card = SortByNumbercard(client, count_client, low_limit, top_limit, count_sort_card);
				for (int i = 0; i < count_sort_card; i++) {
					copy_for_sort_numb_card[i].Show(i);
				}
				cout << "Do you want to save? Yes - 1, No - 2: ";
				int save_choice = GetSaveChoice();
				if (save_choice == 1) {
					InFile(copy_for_sort_numb_card, count_sort_card);
				}
				if (save_choice == 2) {
					break;
				}
				delete[]copy_for_sort_numb_card;
				copy_for_sort_numb_card = nullptr;
			}
			else {
				cout << "No clients" << endl;
			}
		}break;
		case(Not_sort): {
			for (int i = 0; i < count_client; i++) {
				client[i].Show(i);
			}
			cout << "Do you want to save? Yes - 1, No - 2: ";
			int save_choice = GetSaveChoice();
			if (save_choice == 1) {
				InFile(client, count_client);
			}
			if (save_choice == 2) {
				break;
			}
		}break;
		case(Back): {
			exit = true;
		}break;
		default: {
			cout << "Error. Try again." << endl;
		}
		}
	}
}

