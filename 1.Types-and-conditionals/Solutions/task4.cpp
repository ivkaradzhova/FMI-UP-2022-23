#include <iostream>
using namespace std;

int main() {
	unsigned int number, first_digit, second_digit, third_digit;

	cin >> number;

	first_digit = number / 100;
	second_digit = number / 10 % 10;
	third_digit = number % 10;

	float avg = (first_digit + second_digit + third_digit) / 3.0;
	cout << avg << endl;

	return 0;
}
