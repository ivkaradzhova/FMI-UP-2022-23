#include <iostream>
using namespace std;

bool isPossible(long long* days, long long* bonbons, long long size, long long balloons, long long x)
{
	long long counter = 0;
	for (long long i = 0; i < size; i++)
	{
		counter += (days[i] - x / bonbons[i] >= 0 ? days[i] - x / bonbons[i] : 0);
	}
	if (counter <= balloons)
		return true;
	return false;
}

long long binarySearch(long long* days, long long* bonbons, long long size, long long balloons, long long max)
{
	long long l = 0;
	long long r = max;
	long long ans = max;
	while (l <= r)
	{
		long long mid = (l + r) / 2;
		if (isPossible(days, bonbons, size, balloons, mid))
		{
			r = mid - 1;
			ans = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return ans;
}

int main() {
	long long n = 0;
	long long m = 0;
	cin >> n;
	cin >> m;

	long long* days = new long long[n];
	long long* bonbons = new long long[n];

	for (long long i = 0; i < n; i++)
	{
		cin >> days[i];
	}
	cin >> bonbons[0];
	long long max = bonbons[0] * days[0];
	for (long long i = 1; i < n; i++)
	{
		cin >> bonbons[i];
		if (bonbons[i] * days[i] > max)
			max = bonbons[i] * days[i];
	}
	cout << binarySearch(days, bonbons, n, m, max);
	delete[] bonbons;
	delete[] days;
	return 0;
}
