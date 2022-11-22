#include<iostream>

unsigned int reverseNumber(unsigned int number) {
	unsigned int reversed = 0;

	while (number > 0)
	{
		reversed = reversed * 10 + number % 10;
		number /= 10;
	}
	return reversed;
}

int main() {
	unsigned int number;

	std::cin >> number;

	std::cout << (reverseNumber(number) == number) << std::endl;
	return 0;
}
