#include <iostream>
using namespace std;

int main() {
	const float eps = 0.0001;
	float a, b, c;

	cin >> a >> b >> c;

	bool is_triangle = (180 - (a + b + c) < eps && 180 - (a + b + c) > -eps);

	if (is_triangle) {
		if ((90 - a < eps && 90 - a > -eps) || (90 - b < eps && 90 - b > -eps) || (90 - c < eps && 90 - c > -eps)) {
			cout << "rigth triangle" << endl;
		}
		else if (a > 90 || b > 90 || c > 90) {
			cout << "obtuse triangle" << endl;
		}
		else {
			cout << "acute triangle" << endl;
		}
	}
	else {
		cout << "not a triangle" << endl;
	}

	return 0;
}
