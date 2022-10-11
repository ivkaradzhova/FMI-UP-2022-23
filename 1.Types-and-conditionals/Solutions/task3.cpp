#include <iostream>
using namespace std;

int main() {
	const float eps = 0.0001;
	float a, b, c;

	cin >> a >> b >> c;

	cout << (180 - (a + b + c) < eps && 180 - (a + b + c) > -eps) << endl;

	return 0;
}
