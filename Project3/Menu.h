//Menu.h
#pragma once

#include"Function.h"
#include"tests.h"


enum MainMenu {
	Testing=1,
	Input_Menu,
	Get_menu,
	Exit,
};

enum Input_data_menu {
	Input=1,
	Of_file,
	Continue,
};


enum Get_data_menu {
	Sort_by_alphabet=1,
	Sort_by_numbercard,
	Not_sort,
	Back,
};


void MenuMain();
Client* InputMenu(int &count, int *real_count);
void MenuGet(Client *client, int count);