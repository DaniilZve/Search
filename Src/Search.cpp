#include "Stract.h"
#include "Search.h"
#include<string>
using namespace std;

int SumDate(Key k)
{
	return 10000 * k.date.year + 100 * k.date.month + k.date.day; // дата в формате YYYYMMDD

}
string ConcatFIO(Key k)
{
	return  k.fio.f + k.fio.i + k.fio.o;
}

int operator - (string s1, string s2)
{
	int i = 0;
	while (s1[i] == s2[i])
	{
		i += 1;
		if (i == s1.length()) return s1[i];
		if (i == s2.length()) return s2[i];
	}
	return s1[i] - s2[i];
}

bool operator == (Key k1, Key k2)
{
	if ((SumDate(k1) == SumDate(k2)) && (ConcatFIO(k1) == ConcatFIO(k2)) && (k1.Num == k2.Num)) return true;
	else return false;
}

bool CheckSortStract(vector<Key>& ArrKey)
{
	bool sort = true;
	int i = 1;
	while(i < ArrKey.size())
	{
		if (SumDate(ArrKey[i - 1]) > SumDate(ArrKey[i]))
			i += 1;
		else if (SumDate(ArrKey[i - 1]) == SumDate(ArrKey[i]))
		{
			if (ConcatFIO(ArrKey[i - 1]) < ConcatFIO(ArrKey[i]))
				i += 1;
			else if (ConcatFIO(ArrKey[i - 1]) == ConcatFIO(ArrKey[i]))
			{
				if (ArrKey[i - 1].Num <= ArrKey[i].Num)
					i += 1;
				else
				{
					sort = false;
					break;
				}
			}
			else
			{
				sort = false;
				break;
			}
		}
		else
		{
			sort = false;
			break;
		}
	}
	return sort;
}

bool CheckSortNum(vector<Key>& ArrKey)
{
	bool sort = true;
	int i = 1;
	while (i < ArrKey.size())
	{
		if (ArrKey[i - 1].Num <= ArrKey[i].Num)
			i += 1;
		else
		{
			sort = false;
			break;
		}
	}
	return sort;
}


pair <vector<int>, int> LinSearch(vector<Key> &ArrKey, int n, Key &Elem)
{
	int NumSteps = 0;
	int left = 0;
	int right = n - 1;
	pair <vector<int>, int> EntryNums;
	if ((SumDate(Elem) >= SumDate(ArrKey[right])) && (SumDate(Elem) <= SumDate(ArrKey[left])))
	{
		int i = 1;
		while (i < n+1)
		{
			NumSteps += 1;
			if (ArrKey[i - 1] == Elem)
			{
				EntryNums.first.push_back(i);
			}
			i += 1;
		}
	}
	EntryNums.second = NumSteps;
	return EntryNums;
	
}

pair <vector<int>, int> LinSearchNum(vector<Key>& ArrKey, int n, int Num)
{
	int NumSteps = 0;
	int left = 0;
	int right = n - 1;
	pair <vector<int>, int> EntryNums;
	int i = 1;
	if ((Num >= ArrKey[left].Num) && (Num <= ArrKey[right].Num))
	{
		while (i < n + 1)
		{
			if (ArrKey[i - 1].Num == Num) EntryNums.first.push_back(i);
			i += 1;
			NumSteps += 1;
		}
	}
	EntryNums.second = NumSteps;
	return EntryNums;
}

int DateFirst(vector<Key>& ArrKey, Key& Elem, int& NumSteps, int left,int right ) // Первое вхождение по дате 
{
	int mid = 0;
	int AlKey = SumDate(ArrKey[left]);
	int ArKey = SumDate(ArrKey[right]);
	int XKey = SumDate(Elem);
	while ((left <= right) && (XKey >= ArKey) && (XKey <= AlKey))
	{
		AlKey = SumDate(ArrKey[left]);
		ArKey = SumDate(ArrKey[right]);
		XKey = SumDate(Elem);
		if ((ArKey != AlKey))
		{
			mid = (((long long)(AlKey - XKey) * (right - left)) / (AlKey - ArKey)) + left;
			NumSteps += 1;
		}
		else if (AlKey == XKey)
			return left;
		else
			return -1;

		int AmKey = SumDate(ArrKey[mid]);
		if (XKey < AmKey)
			left = (mid + 1);
		else if (XKey > AmKey)
			right = (mid - 1);
		else
		{
			right = (mid - 1);
			if ((right < 0) || (SumDate(ArrKey[right]) != XKey))
				return mid;
			
		}
	}
	return -1;	
}

int DateLast(vector<Key>& ArrKey, Key& Elem, int& NumSteps, int left, int right) // Последнее вхождение по дате 
{
	if ((left != -1) && (right != -1))
	{
		int mid = 0;
		int AlKey = SumDate(ArrKey[left]);
		int ArKey = SumDate(ArrKey[right]);
		int XKey = SumDate(Elem);
		while ((left <= right) && (XKey >= ArKey) && (XKey <= AlKey))
		{
			AlKey = SumDate(ArrKey[left]);
			ArKey = SumDate(ArrKey[right]);
			XKey = SumDate(Elem);
			if ((ArKey != AlKey))
			{
				mid = (((long long)(AlKey - XKey) * (right - left)) / (AlKey - ArKey)) + left;
				NumSteps += 1;
			}
			else if (ArKey == XKey)
				return right;
			else
				return -1;

			int AmKey = SumDate(ArrKey[mid]);
			if (XKey < AmKey)
				left = (mid + 1);
			else if (XKey > AmKey)
				right = (mid - 1);
			else
			{
				left = (mid + 1);
				if ((left > ArrKey.size() - 1) || (SumDate(ArrKey[left]) != XKey))
					return mid;

			}
		}
	}
	return -1;
}

int FIOFirst(vector<Key>& ArrKey, Key& Elem, int& NumSteps, int left, int right)// Первое вхождение по дате 
{
	if ((left != -1) && (right != -1))
	{
		int mid = 0;
		string AlKey = ConcatFIO(ArrKey[left]);
		string ArKey = ConcatFIO(ArrKey[right]);
		string XKey = ConcatFIO(Elem);
		while ((left <= right) && (XKey >= AlKey) && (XKey <= ArKey))
		{
			AlKey = ConcatFIO(ArrKey[left]);
			ArKey = ConcatFIO(ArrKey[right]);
			XKey = ConcatFIO(Elem);
			if ((ArKey != AlKey))
			{
				mid = ((XKey - AlKey) * (right - left)) / (ArKey - AlKey) + left;
				NumSteps += 1;
			}
			else if (AlKey == XKey)
				return left;
			else
				return -1;

			string AmKey = ConcatFIO(ArrKey[mid]);
			if (XKey < AmKey)
				right = (mid - 1);
			else if (XKey > AmKey)
				left = (mid + 1);
			else
			{
				right = (mid - 1);
				if ((right < 0) || (ConcatFIO(ArrKey[right]) != XKey))
					return mid;;
			}
		}
	}
	return -1;
}

int FIOLast(vector<Key>& ArrKey, Key& Elem, int& NumSteps, int left, int right)// Последнее вхождение по ФИО
{
	if ((left != -1) && (right != -1))
	{
		int mid = 0;
		string AlKey = ConcatFIO(ArrKey[left]);
		string ArKey = ConcatFIO(ArrKey[right]);
		string XKey = ConcatFIO(Elem);
		while ((left <= right) && (XKey >= AlKey) && (XKey <= ArKey))
		{
			AlKey = ConcatFIO(ArrKey[left]);
			ArKey = ConcatFIO(ArrKey[right]);
			XKey = ConcatFIO(Elem);
			if ((ArKey != AlKey))
			{
				mid = ((XKey - AlKey) * (right - left)) / (ArKey - AlKey) + left;
				NumSteps += 1;
			}
			else if (ArKey == XKey)
				return right;
			else
				return -1;

			string AmKey = ConcatFIO(ArrKey[mid]);
			if (XKey < AmKey)
				right = (mid - 1);
			else if (XKey > AmKey)
				left = (mid + 1);
			else
			{
				left = (mid + 1);
				if ((left > ArrKey.size() - 1) || (ConcatFIO(ArrKey[left]) != XKey))
					return mid;

			}
		}
	}
	return -1;
}

int NumFirst(vector<Key>& ArrKey, int Elem, int& NumSteps, int left, int right)// Первое вхождение по номеру заявки
{
	if ((left != -1) && (right != -1))
	{
		int mid = 0;
		int AlKey = ArrKey[left].Num;
		int ArKey = ArrKey[right].Num;
		int XKey = Elem;
		while ((left <= right) && (XKey >= AlKey) && (XKey <= ArKey))
		{
			AlKey = ArrKey[left].Num;
			ArKey = ArrKey[right].Num;
			XKey = Elem;
			if ((ArKey != AlKey))
			{
				mid = ((XKey - AlKey) * (right - left)) / (ArKey - AlKey) + left;
				NumSteps += 1;
			}
			else if (AlKey == XKey)
				return left;
			else
				return -1;

			int AmKey = ArrKey[mid].Num;
			if (XKey < AmKey)
				right = (mid - 1);
			else if (XKey > AmKey)
				left = (mid + 1);
			else
			{
				right = (mid - 1);
				if ((right < 0) || (ArrKey[right].Num != XKey))
					return mid;
			}
		}
	}
	return -1;
}

int NumLast(vector<Key>& ArrKey, int Elem, int& NumSteps, int left, int right)// Последнее вхождение по номеру заявки
{
	if ((left != -1) && (right != -1))
	{
		int mid = 0;
		int AlKey = ArrKey[left].Num;
		int ArKey = ArrKey[right].Num;
		int XKey = Elem;
		while ((left <= right) && (XKey >= AlKey) && (XKey <= ArKey))
		{
			AlKey = ArrKey[left].Num;
			ArKey = ArrKey[right].Num;
			XKey = Elem;
			if ((ArKey != AlKey))
			{
				mid = ((XKey - AlKey) * (right - left)) / (ArKey - AlKey) + left;
				NumSteps += 1;
			}
			else if (ArKey == XKey)
				return right;
			else
				return -1;

			int AmKey = ArrKey[mid].Num;
			if (XKey < AmKey)
				right = (mid - 1);
			else if (XKey > AmKey)
				left = (mid + 1);
			else
			{
				left = (mid + 1);
				if ((left > ArrKey.size() - 1) || (ArrKey[left].Num != XKey))
					return mid;

			}
		}
	}
	return -1;
}
pair <vector<int>, int> InterPolSearch(vector<Key>& ArrKey, int n, Key &Elem)
{
	bool sort = true;
	int NumSteps = 0;
	int left = 0;
	int right = n - 1;
	pair <vector<int>, int> EntryNums;
	
	if (!ArrKey.empty())
	{
		
		if (CheckSortStract(ArrKey) == true)
		{
			left = DateFirst(ArrKey, Elem, NumSteps, left, right);
			right = DateLast(ArrKey, Elem, NumSteps, left, right);
			left = FIOFirst(ArrKey, Elem, NumSteps, left, right);
			right = FIOLast(ArrKey, Elem, NumSteps, left, right);
			left = NumFirst(ArrKey, Elem.Num, NumSteps, left, right);
			right = NumLast(ArrKey, Elem.Num, NumSteps, left, right);

			while ((left <= right) && (left != -1) && (right != -1))
			{
				NumSteps += 1;
				EntryNums.first.push_back(left + 1);
				left += 1;
			}
			EntryNums.second = NumSteps;
		}
		else
		{
			cout << "Список не отсортирован" << endl;
			return EntryNums;
		}
	}
	else
		cout << "Список пуст";
	return EntryNums;

}

pair <vector<int>, int> InterPolSearchNum(vector<Key>& ArrKey, int n, int Elem)
{
	bool sort = true;
	int NumSteps = 0;
	int left = 0;
	int right = n - 1;
	pair <vector<int>, int> EntryNums;

	if (!ArrKey.empty())
	{

		if (CheckSortNum(ArrKey) == true)
		{
			left = NumFirst(ArrKey, Elem, NumSteps, left, right);

			while ((left != -1) && (ArrKey[left].Num == Elem))
			{
				NumSteps += 1;
				EntryNums.first.push_back(left + 1);
				left += 1;
			}
			EntryNums.second = NumSteps;
		}
		else
		{
			cout << "Список не отсортирован" << endl;
			return EntryNums;
		}
	}
	else
		cout << "Список пуст";
	return EntryNums;

}