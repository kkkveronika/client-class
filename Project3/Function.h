//Function.h
#pragma once

#include<fstream>
#include"Class.h"
#include "Correct_input.h"
using namespace std;

Client* CreateArray(int count);

Client* FromFile(int count, int *realCount);

Client* SortByName(Client *client, int count);

int FoundCountSortCard(Client *copy_client, int count, int low_lim, int top_lim);

Client* SortByNumbercard(Client *copy_client, int count, int low_lim, int top_lim, int c_sort_card);

bool CheckExistanceData(Client* client, int count);

void InFile(Client* client, int count);