Client** func_array(int Count) {
	Client **array;
	array = new Client*[Count];
	for (int i = 0; i < Count; i++) {
		array[i] = new Client[Count];
	}
	return array;
}



int Count = {};
string Str = "";
unsigned long long int numb = 0;
cout << "¬ведите количество клиентов: ";
cin >> Count;
Client* array = new Client[Count];
array[0] = Client("dfg", "dfhgh", "dfghfj", "sdgfgh", "hnjm", 5, 3456, 345, 345);
for (int i = 0; i < Count; i++) {
	cout << "¬ведите фамилию: ";
	Str = GetString();
	array[i].setSurename(Str);
	cout << "¬ведите им€: ";
	Str = GetString();
	array[i].setName(Str);
	cout << "¬ведите отчество: ";
	Str = GetString();
	array[i].setSecond_name(Str);
	cout << "¬ведите город : ";
	Str = GetString();
	array[i].setCity(Str);
	cout << "¬ведите улицу: ";
	Str = GetString();
	array[i].setStreet(Str);
	cout << "¬ведите дом: ";
	numb = GetInt();
	array[i].setHouse(numb);
	cout << "¬ведите номер карты: ";
	numb = GetLongInt();
	array[i].setNumber_card(numb);
	cout << "¬ведите номер банковского счета: ";
	numb = GetLongInt();
	array[i].setNumb_bank_account(numb);
	cout << "¬ведите номер телефона: ";
	numb = GetLongInt();
	array[i].setPhone_numb(numb);

}
for (int i = 0; i < Count; i++) {
	array[i].Show(i);
}
		}break;