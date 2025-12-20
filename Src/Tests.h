#pragma once
#include <vector> 
#include <string>
#include <fstream>
#include"Stract.h"

vector <Key> ReadFromFtoArr(ifstream& in);
void PrintRes(pair <vector<int>, int> &ResultIn);
void WriteFromArrtoF(ofstream& out, vector<Key> ArrKey);