//Function.cpp
#include"Function.h"
#include <filesystem> 

using namespace filesystem;


Client* CreateArray(int count) {
	Client* client = new Client[count];
	string Str = "";
	int numb = 0;
	int numbint = 0;
	for (int i = 0; i < count; i++) {
		cout << "Enter surename: ";
		Str = GetString();
		client[i].setSurename(Str);
		cout << "Enter name: ";
		Str = GetString();
		client[i].setName(Str);
		cout << "Enter second name: ";
		Str = GetString();
		client[i].setSecondName(Str);
		cout << "Enter city: ";
		Str = GetString();
		client[i].setCity(Str);
		cout << "Enter street: ";
		Str = GetString();
		client[i].setStreet(Str);
		cout << "Enter house: ";
		numbint = GetInt();
		client[i].setHouse(numbint);
		cout << "Enter card number: ";
		numb = GetInt();
		client[i].setNumberCard(numb);
		cout << "Enter bank account number: ";
		numb = GetInt();
		client[i].setNumbBankAccount(numb);
		cout << "Enter phone numb: ";
		numb = GetInt();
		client[i].setPhoneNumb(numb);
	}
	return client;
}

Client* FromFile(int count, int *realCount) {
	Client* client = new Client[count];
	cout << "Enter the name of file(without file permission!): ";
	string name_file = "";
	cin >> name_file;
	ifstream file;
	file.open(name_file);
	int i = 0;
	int k = 0;

	//if (!(file >> count)) {
	//	cout << "Wrong number of clients" << endl;
	//	file.close();
	//}
	if (!file.is_open()) {
		cout << "File opening error" << endl;
	}
	else {
		while (!file.eof()) {
			k++;
			if (k > count) {
				cout << "Wrong number of clients" << endl;
				file.close();
				break;
			}
			string surename = "";
			string name = "";
			string second_name = "";
			string city = "";
			string street = "";
			int house{};
			int number_card{};
			int numb_bank_account{};
			int phone_numb{};
			file >> surename;
			file >> name;
			file >> second_name;
			file >> city;
			file >> street;
			file >> house;
			file >> number_card;
			file >> numb_bank_account;
			file >> phone_numb;
			client[i] = Client(surename, name, second_name, city, street, house, number_card, numb_bank_account, phone_numb);
			i++;
		}
		if (k == count) {
			cout << "Download completed" << endl;
		}
		if (k < count) {
			cout << "Download completed. " << k << " files have been loaded." << endl;
		}
	}
	file.close();
	*realCount = k;
	return client;
}


Client* SortByName(Client *copy_client_name, int count) {
	Client tmp;
	for (int i = 0; i <= count; i++) {
		for (int j = 1; j < count; j++) {
			if (copy_client_name[j - 1].getSurename() > copy_client_name[j].getSurename()) {
				tmp = copy_client_name[j - 1];
				copy_client_name[j - 1] = copy_client_name[j];
				copy_client_name[j] = tmp;
			}
			if (copy_client_name[j - 1].getSurename() == copy_client_name[j].getSurename()) {
				if (copy_client_name[j - 1].getName() > copy_client_name[j].getName()) {
					tmp = copy_client_name[j - 1];
					copy_client_name[j - 1] = copy_client_name[j];
					copy_client_name[j] = tmp;
				}
				if (copy_client_name[j - 1].getName() == copy_client_name[j].getName()) {
					if (copy_client_name[j - 1].getSecondName() > copy_client_name[j].getSecondName()) {
						tmp = copy_client_name[j - 1];
						copy_client_name[j - 1] = copy_client_name[j];
						copy_client_name[j] = tmp;
					}
				}
			}
		}
	}
	return copy_client_name;
}

int FoundCountSortCard(Client *copy_client, int count, int low_lim, int top_lim) {
	int count_sort_card = {};
	for (int i = 0; i < count; i++) {
		if (copy_client[i].getNumberCard() >= low_lim && copy_client[i].getNumberCard() <= top_lim)
			count_sort_card += 1;
	}
	return count_sort_card;
}

Client* SortByNumbercard(Client *copy_client, int count, int low_lim, int top_lim, int c_sort_card) {
	Client* SortArray = new Client[c_sort_card];
	int tmp = c_sort_card;
	for (int i = 0; i < count; i++) {
		if (copy_client[i].getNumberCard() >= low_lim && copy_client[i].getNumberCard() <= top_lim) {
			SortArray[c_sort_card - tmp].setName(copy_client[i].getName());
			SortArray[c_sort_card - tmp].setSurename(copy_client[i].getSurename());
			SortArray[c_sort_card - tmp].setSecondName(copy_client[i].getSecondName());
			SortArray[c_sort_card - tmp].setCity(copy_client[i].getCity());
			SortArray[c_sort_card - tmp].setStreet(copy_client[i].getStreet());
			SortArray[c_sort_card - tmp].setHouse(copy_client[i].getHouse());
			SortArray[c_sort_card - tmp].setNumbBankAccount(copy_client[i].getNumbBankAccount());
			SortArray[c_sort_card - tmp].setNumberCard(copy_client[i].getNumberCard());
			SortArray[c_sort_card - tmp].setPhoneNumb(copy_client[i].getPhoneNumb());
			tmp--;
		}
	}
	return SortArray;
}

bool CheckExistanceData(Client* client, int count) {
	bool flag = true;
	if (count != 0) {
		for (int i = 0; i < count; i++) {
			if (client[i].getName() == "" && client[i].getSurename() == "" && client[i].getSecondName() == "" && client[i].getCity() == "" && client[i].getStreet() == "" && client[i].getHouse() == 0 && client[i].getNumbBankAccount() == 0 && client[i].getNumberCard() == 0 && client[i].getPhoneNumb() == 0) {
				flag = false;
			}
		}
	}
	else {
		flag = false;
	}
	return flag;
}

void InFile(Client* client, int count) {
	int tryAnotherFile{};
	ofstream fout;
	string name_file{};
	cout << "Enter the name of file(without file permission!): ";
	cin >> name_file;
	if (ifstream(name_file)) {
		cout << "The file exists." << endl;
		cout << "Overwrite existing file - 0\nEnter again - 1\nChoose: ";
		tryAnotherFile = GetBool();
	}
	fout.open(name_file);
	 // ф-ция open, если не находит файл с таким именем, сама его создает(app не затирает предыдущие данные).
	if ((!fout.is_open())) {
		cout << "Fail opening error";
	}
	else {
		if (tryAnotherFile == 0) {
			for (int i = 0; i < count; i++) {
				fout << "Client №" << i + 1 << "\n" << "Full name:  " << client[i].getSurename() << " " << client[i].getName() << " " << client[i].getSecondName() //
					<< "\n" << "Adress:  " << client[i].getCity() << ", " << client[i].getStreet() << ", " << client[i].getHouse() << " " << "\n" << "Card number:  " //
					<< client[i].getNumberCard() << "\n" << "Bank account number:  " << client[i].getNumbBankAccount() << "\n" << "Phone number:  " << client[i].getPhoneNumb() << "\n";
			}
		}
		if (tryAnotherFile == 1) {
			InFile(client, count);
		}
	}
	fout.close();
}

class A {
public:
	void printf() {

	}
};

class B : public A {
public:
	void printf() {

	}
};

