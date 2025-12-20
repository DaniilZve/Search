#pragma once
#include "Stract.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
int SumDate(Key k); // дата в формате числа YYYYMMDD
string ConcatFIO(Key k);

pair <vector<int>, int> LinSearch(vector<Key>& ArrKey, int n, Key &Elem);
bool CheckSort(vector<Key>& ArrKey);
int DateFirst(vector<Key>& ArrKey, Key& Elem, int& NumSteps, int left, int right);
int DateLast(vector<Key>& ArrKey, Key& Elem, int& NumSteps, int left, int right);
int FIOFirst(vector<Key>& ArrKey, Key& Elem, int& NumSteps, int left, int right);
int FIOLast(vector<Key>& ArrKey, Key& Elem, int& NumSteps, int left, int right);
int NumFirst(vector<Key>& ArrKey, Key& Elem, int& NumSteps, int left, int right);
int NumLast(vector<Key>& ArrKey, Key& Elem, int& NumSteps, int left, int right);
pair <vector<int>, int> InterPolSearch(vector<Key>& ArrKey, int n, Key &Elem);
