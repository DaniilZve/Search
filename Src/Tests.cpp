#include"Tests.h"
vector <Key> ReadFromFtoArr(ifstream& in)
{
	string D;
	Key Elem;
	vector <Key> ArrKey;
	int n = 1;
	if (in.is_open())
	{
		while (in >> D >> Elem.fio.f >> Elem.fio.i >> Elem.fio.o >> Elem.Num)
		{
			Elem.date.day = stoi(D.substr(0, 2));
			Elem.date.month = stoi(D.substr(3, 2));
			Elem.date.year = stoi(D.substr(6, 4));
			ArrKey.push_back(Elem);
		}
	}
	else
		cout << "Текстовый файл не найден" << endl;
	return ArrKey;
}
void PrintRes(pair <vector<int>, int>& ResultIn)
{
	if (ResultIn.first.size() != 0)
	{
		for (int i = 0; i < ResultIn.first.size(); i++)
			cout << ResultIn.first[i] << " ";
	}
	else
		cout << "Элементы не найдены";
	cout << "\nЧисло шагов: " << ResultIn.second << endl;
}