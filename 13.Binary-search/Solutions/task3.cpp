#include <iostream>
using namespace std;

long long binarySearch(long long* arr, long long size, long long x)
{
	long long l = 0;
	long long r = size - 1;
	long long ans = size;
	while (l <= r)
	{
		long long mid = (l + r) / 2;
		if (x > arr[mid])
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
			ans = mid;
		}
	}
	return ans;
}

int main() {
	long long n = 0;
	long long sum = 0;
	long long m = 0;
	cin >> n;
	long long* a = new long long[n];
	for (long long i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
		a[i] = sum;
	}

	cin >> m;
	long long* q = new long long[m];
	for (long long i = 0; i < m; i++)
	{
		cin >> q[i];
	}
	for (long long i = 0; i < m - 1; i++)
	{
		cout << binarySearch(a, n, q[i]) + 1 << endl;
	}
	cout << binarySearch(a, n, q[m - 1]) + 1;
	delete[] a;
	delete[] q;
	return 0;
}
