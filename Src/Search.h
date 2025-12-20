#pragma once
#include "Stract.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
int SumDate(Key k); // дата в формате числа YYYYMMDD
string ConcatFIO(Key k);

pair <vector<int>, int> LinSearchNum(vector<Key>& ArrKey, int n, int Num);
pair <vector<int>, int> LinSearch(vector<Key>& ArrKey, int n, Key &Elem);
bool CheckSortStract(vector<Key>& ArrKey);
bool CheckSortNum(vector<Key>& ArrKey);
int DateFirst(vector<Key>& ArrKey, Key& Elem, int& NumSteps, int left, int right);
int DateLast(vector<Key>& ArrKey, Key& Elem, int& NumSteps, int left, int right);
int FIOFirst(vector<Key>& ArrKey, Key& Elem, int& NumSteps, int left, int right);
int FIOLast(vector<Key>& ArrKey, Key& Elem, int& NumSteps, int left, int right);
int NumFirst(vector<Key>& ArrKey, int Elem, int& NumSteps, int left, int right);
int NumLast(vector<Key>& ArrKey, int Elem, int& NumSteps, int left, int right);
pair <vector<int>, int> InterPolSearchNum(vector<Key>& ArrKey, int n, int Elem);
pair <vector<int>, int> InterPolSearch(vector<Key>& ArrKey, int n, Key &Elem);
