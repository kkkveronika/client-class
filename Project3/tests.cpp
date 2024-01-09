//tests.cpp
#include"tests.h"

void Test() {
	bool check_test1{};
	bool check_test2{};
	bool check_test3{};
	bool check_test4{};
	bool check_test5{};
	bool check_test6{};
	bool check_test7{};
	int Test_count = 0;
	int i = 1;

	Client Test1[3] = { {"c", "c", "c", "c", "c", 1, 12, 1, 1}, {"a", "a", "a", "a", "a", 1, 2, 1, 1}, {"b", "b", "b", "b", "b", 1, 20, 1, 1} };
	Client ResultTest1[3] = { {"a", "a", "a", "a", "a", 1, 2, 1, 1}, {"b", "b", "b", "b", "b", 1, 20, 1, 1}, {"c", "c", "c", "c", "c", 1, 12, 1, 1} };
	*Test1 = *SortByName(Test1, 3);
	check_test1 = TestComparison(Test1, ResultTest1, 3, i);
	i += 1;


	Client Test2[3] = { {"g", "d", "c", "c", "c", 1, 12, 1, 1}, {"g", "s", "a", "a", "a", 1, 2, 1, 1}, {"g", "a", "b", "b", "b", 1, 20, 1, 1} };
	Client ResultTest2[3] = { {"g", "a", "b", "b", "b", 1, 20, 1, 1}, {"g", "d", "c", "c", "c", 1, 12, 1, 1}, {"g", "s", "a", "a", "a", 1, 2, 1, 1} };
	*Test2 = *SortByName(Test2, 3);
	check_test2 = TestComparison(Test2, ResultTest2, 3, i);
	i += 1;

	Client Test3[3] = { {"p", "p", "c", "c", "c", 1, 12, 1, 1}, {"p", "p", "a", "a", "a", 1, 2, 1, 1}, {"p", "p", "m", "b", "b", 1, 20, 1, 1} };
	Client ResultTest3[3] = { {"p", "p", "a", "a", "a", 1, 2, 1, 1}, {"p", "p", "c", "c", "c", 1, 12, 1, 1}, {"p", "p", "m", "b", "b", 1, 20, 1, 1} };
	*Test3 = *SortByName(Test3, 3);
	check_test3 = TestComparison(Test3, ResultTest3, 3, i);
	i += 1;

	Client Test4[3] = { {"p", "p", "p", "c", "c", 1, 12, 1, 1}, {"p", "p", "p", "a", "a", 1, 2, 1, 1}, {"p", "p", "p", "b", "b", 1, 20, 1, 1} };
	Client ResultTest4[3] = { {"p", "p", "p", "c", "c", 1, 12, 1, 1}, {"p", "p", "p", "a", "a", 1, 2, 1, 1}, {"p", "p", "p", "b", "b", 1, 20, 1, 1} };
	*Test4 = *SortByName(Test4, 3);
	check_test4 = TestComparison(Test4, ResultTest4, 3, i);
	i += 1;

	Client Test5[3] = { {"p", "p", "p", "c", "c", 1, 12, 1, 1}, {"p", "p", "p", "a", "a", 1, 2, 1, 1}, {"p", "p", "p", "b", "b", 1, 20, 1, 1} };
	Client ResultTest5[2] = { {"p", "p", "p", "c", "c", 1, 12, 1, 1}, {"p", "p", "p", "b", "b", 1, 20, 1, 1} };
	int Result_test_count1 = 2;
	Test_count = FoundCountSortCard(Test5, 3, 10, 25);
	Client* test5 = new Client[Test_count];
	test5 = SortByNumbercard(Test5, 3, 10, 25, Test_count);
	check_test5 = TestComparisonByCount(test5, ResultTest5, Result_test_count1, Test_count, i);
	i += 1;

	Client Test6[3] = { {"p", "p", "p", "c", "c", 1, 12, 1, 1}, {"p", "p", "p", "a", "a", 1, 20, 1, 1}, {"p", "p", "p", "b", "b", 1, 2, 1, 1} };
	Client ResultTest6[1] = { {"p", "p", "p", "b", "b", 1, 2, 1, 1} };
	int Result_test_count2 = 1;
	Test_count = FoundCountSortCard(Test6, 3, 1, 5);
	Client* test6 = new Client[Test_count];
	test6 = SortByNumbercard(Test6, 3, 1, 5, Test_count);
	check_test6 = TestComparisonByCount(test6, ResultTest6, Result_test_count2, Test_count, i);
	i += 1;

	Client Test7[3] = { {"p", "p", "p", "c", "c", 1, 12, 1, 1}, {"p", "p", "p", "a", "a", 1, 2, 1, 1}, {"p", "p", "p", "b", "b", 1, 20, 1, 1} };
	int Result_test_count3 = 0;
	Test_count = FoundCountSortCard(Test7, 3, 25, 50);
	if (Result_test_count3 == Test_count) {
		check_test7 = true;
	}
	else {
		check_test7 = false;
	}

	if (check_test1 == true && check_test2 == true && check_test3 == true && check_test4 == true && check_test5 == true && check_test6 == true && check_test7 == true) {
		cout << endl << "Test passed" << endl << endl;
	}
}