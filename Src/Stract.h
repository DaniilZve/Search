#pragma once
#include<iostream>
using namespace std;
struct Date {
	int day = 0;
	int month = 0;
	int year = 0;
};

struct FIO {
	string f = "";
	string i = "";
	string o = "";
};

struct Key {
	Date date;
	FIO fio;
	unsigned int Num = 0;
};

