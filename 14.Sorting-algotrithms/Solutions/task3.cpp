#include <iostream>
using namespace std;

long long Merge(long long* arr, long long start, long long middle, long long end);

long long MergeSort(long long* arr, long long start, long long end)
{
	long long counter = 0;
	if (start < end)
	{
		long long middle = start + (end - start) / 2;
		counter += MergeSort(arr, start, middle);
		counter += MergeSort(arr, middle + 1, end);
		counter += Merge(arr, start, middle, end);
	}
	return counter;
}

long long Merge(long long* arr, long long start, long long middle, long long end)
{
	long long i = start;
	long long j = middle + 1;
	long long k = 0;
	long long counter = 0;
	long long* tempArr = new long long[end - start + 1];
	while (i <= middle && j <= end)
	{
		if (arr[i] <= arr[j])
		{
			tempArr[k] = arr[i];
			i++;
		}
		else
		{
			tempArr[k] = arr[j];
			j++;
			counter += middle + 1 - i;
		}
		k++;
	}
	while (i <= middle)
	{
		tempArr[k] = arr[i];
		i++;
		k++;
	}
	while (j <= end)
	{
		tempArr[k] = arr[j];
		j++;
		k++;
	}
	for (long long index = 0; index < k; index++)
	{
		arr[start + index] = tempArr[index];
	}
	delete[] tempArr;
	return counter;
}

int main() {
	long long n = 0;
	long long counter = 0;

	cin >> n;
	if (n == 0)
	{
		cout << 0;
		return 0;
	}
	long long* buildings = new long long[n];
	if (n == 1)
	{
		cout << 0;
		return 0;
	}
	for (long long i = 0; i < n; i++)
	{
		cin >> buildings[i];
	}
	counter += MergeSort(buildings, 0, n - 1);
	cout << counter;
	return 0;
}
