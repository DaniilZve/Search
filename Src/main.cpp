#include "Stract.h"
#include "Tests.h"
#include "Search.h"
#include "MergeSort.h"
int main()
{
	setlocale(LC_ALL, "rus");
	string SortFileForSearchStract = "Static/Input10k.txt";
	ifstream in(SortFileForSearchStract);
	vector<Key> ArrKey = ReadFromFtoArr(in);// дл€ случа€ когда ищем по всей структуре
	in.close();


	vector<Key> SortArrNum = MergerSort(ArrKey, ArrKey.size()); // сортировка по номеру за€вки

	string SortFileForSearchNum = "Static/SortFileForSearchNum.txt"; 
	ofstream outSortNum(SortFileForSearchNum);
	WriteFromArrtoF(outSortNum, SortArrNum);// запись результата в outSortNum
	outSortNum.close();

	ifstream inNum(SortFileForSearchNum);
	vector<Key> ArrKeyNum = ReadFromFtoArr(inNum);// дл€ случа€ когда ищем по номеру за€вки
	inNum.close();


	Key SerchElem; // структура которую будем искать
	//07.09.1961 Stepanov Sergey Nikolaevich 1
	SerchElem.date.day = 7; SerchElem.date.month = 9; SerchElem.date.year = 1961;
	SerchElem.fio.f = "Stepanov"; SerchElem.fio.i = "Sergey"; SerchElem.fio.o = "Nikolaevich";
	SerchElem.Num = 1;
	int n = ArrKey.size();
	int nNum = ArrKeyNum.size();

	int SearchNumber = 1; // номер за€вки по которому будем искать


	if (n != 0)
	{
		pair <vector<int>, int> ResultLinNum = LinSearchNum(ArrKeyNum, nNum, SearchNumber);
		cout << "Ћинейный поиск по номеру за€вки в отсортированном по ней "<< SortFileForSearchNum << endl;
		PrintRes(ResultLinNum);

		cout << endl;

		pair <vector<int>, int> ResultInterPolNum = InterPolSearchNum(ArrKeyNum, nNum, SearchNumber);
		cout << "»нтерпол€ционный поиск по номеру за€вки в отсортированном по ней "<< SortFileForSearchNum << endl;
		PrintRes(ResultInterPolNum);

		cout << endl;

		pair <vector<int>, int> ResultLin = LinSearch(ArrKey, n, SerchElem);
		cout << "Ћинейный поиск по всей структуре в " << SortFileForSearchStract <<endl;
		PrintRes(ResultLin);

		cout << endl;

		pair <vector<int>, int> ResultInterpol = InterPolSearch(ArrKey, n, SerchElem);
		cout << "»нтерпол€ционный поиск по всей структуре " << SortFileForSearchStract << endl;
		PrintRes(ResultInterpol);
	}
	else
		cout << "¬ходной файл пуст" << endl;

	return 0;
}