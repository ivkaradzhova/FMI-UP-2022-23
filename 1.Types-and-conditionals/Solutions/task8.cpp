#include <iostream>
using namespace std;

int main() {
	double a, b, c, d, eps = 0.00001;

	cin >> a >> b >> c;

	if (a <= eps && a >= -eps) {
		if (b <= eps && b >= -eps) {
			if (c <= eps && c >= -eps) {
				cout << "all real numbers" << endl;
			}
			else {
				cout << "no solution" << endl;
			}
		}
		else {
			cout << "one root" << endl;
		}
		return 0;
	}

	d = b * b - 4 * a * c;
	if (d > eps) {
		cout << "two roots" << endl;
	}
	else if (d >= -eps) {
		cout << "one root" << endl;
	}
	else {
		cout << "no real root" << endl;
	}
	return 0;
}
