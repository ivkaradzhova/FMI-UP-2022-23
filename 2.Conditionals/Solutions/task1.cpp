#include <iostream>
using namespace std;

int main() {
	double a, b, c, d;

	cin >> a >> b >> c >> d;

	double min = a;
	double max = a;

	if (b > max) {
		max = b;
	}
	else if (b < min) {
		min = b;
	}

	max = max < c ? c : max;
	min = min > c ? c : min;

	switch (min > d)
	{
	case true: min = d;
	}

	switch (max < d)
	{
	case true: max = d;
	}

	cout << min << endl;
	cout << max << endl;
	return 0;
}
