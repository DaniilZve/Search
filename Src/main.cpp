#include "Stract.h"
#include "Tests.h"
#include "Search.h"
int main()
{
	setlocale(LC_ALL, "rus");
	ifstream in("Static/TestIn.txt");
	vector<Key> ArrKey = ReadFromFtoArr(in);
	in.close();

	Key SerchElem;
	//24.03.1986 Popov Natalia Andreevna 469
	SerchElem.date.day = 24; SerchElem.date.month = 3; SerchElem.date.year = 1986;
	SerchElem.fio.f = "Popov"; SerchElem.fio.i = "Natalia"; SerchElem.fio.o = "Andreevna";
	SerchElem.Num = 469;
	int n = ArrKey.size();


	if (n != 0)
	{
		pair <vector<int>, int> ResultLin = LinSearch(ArrKey, n, SerchElem);
		cout << "Ћинейный поиск" << endl;
		PrintRes(ResultLin);

		cout << endl;

		pair <vector<int>, int> ResultInterpol = InterPolSearch(ArrKey, n, SerchElem);
		cout << "»нтерпол€ционный поиск" << endl;
		PrintRes(ResultInterpol);



	}
	else
		cout << "¬ходной файл пуст" << endl;

	
	return 0;
}