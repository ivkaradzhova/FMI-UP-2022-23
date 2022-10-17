#include <iostream>
using namespace std;

int main() {
	double a, b, x;

	cin >> a >> b >> x;

	cout << "f'(x) = " << a * b << " * x^" << b - 1 << " = " << a * b * pow(x, b - 1) << endl;
	return 0;
}
