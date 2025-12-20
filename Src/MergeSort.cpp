#include "MergeSort.h"
#include "Search.h"


vector<Key> merger(vector<Key>& vek1, vector<Key>& vek2)
{
	int i = 0;
	int j = 0;
	int size1 = vek1.size();
	int size2 = vek2.size();
	vector<Key> result;

	while ((i < size1) && (j < size2) && ((size1 != 0) && (size2 != 0)))
	{

		if (vek1[i].Num <= vek2[j].Num)
		{
			result.push_back(vek1[i]);
			i += 1;
		}
		else
		{
			result.push_back(vek2[j]);
			j += 1;
		}
	}

	if ((size1 == 0)) return vek2;
	else if ((size2 == 0)) return vek1;

	if (i == size1)
	{
		for (j; j < size2;j += 1)
			result.push_back(vek2[j]);
	}
	else if (j == size2)
	{
		for (i; i < size1;i += 1)
			result.push_back(vek1[i]);
	}

	return result;
}

vector<Key> MergerSort(vector<Key> result, int n)
{
	int i = 0;
	int start;
	int LengthSortArr = 0;
	while (LengthSortArr < n)
	{
		start = i;
		vector <Key> arr1;
		do
		{
			arr1.push_back(result[i]);
			i += 1;
			if (i >= n) break;
		} while (result[i].Num >= result[i-1].Num);


		vector <Key> arr2;
		if (i < n)
		{
			do
			{
				arr2.push_back(result[i]);
				i += 1;
				if (i >= n) break;
			} while (result[i].Num >= result[i - 1].Num);
		}

		vector<Key> ResultMerg(arr1.size() + arr2.size());
		ResultMerg = merger(arr1, arr2);


		LengthSortArr = 0;
		while (start < i)
		{
			result[start] = ResultMerg[LengthSortArr];
			LengthSortArr += 1;
			start += 1;
		}

		if (i >= n)
		{
			start = 0;
			i = 0;
		}

	}
	return result;
}