#include <iostream>
using namespace std;

int main() {
	unsigned int a;

	cin >> a;

	if (a < 10 || a > 99) {
		cout << "It's not a two-digit number!" << endl;
		return 0;
	}

	if (a < 20) {
		switch (a)
		{
		case 10: cout << "ten" << endl; break;
		case 11: cout << "eleven" << endl; break;
		case 12: cout << "twelve" << endl; break;
		case 13: cout << "thirteen" << endl; break;
		case 14: cout << "fourteen" << endl; break;
		case 15: cout << "fifteen" << endl; break;
		case 16: cout << "sixteen" << endl; break;
		case 17: cout << "seventeen" << endl; break; 
		case 18: cout << "eighteen" << endl; break;
		case 19: cout << "nineteen" << endl; break;
		}
		return 0;
	}

	switch (a / 10)
	{
	case 2: cout << "twenty"; break;
	case 3: cout << "thirty"; break;
	case 4: cout << "forty"; break;
	case 5: cout << "fifty"; break;
	case 6: cout << "sixty"; break;
	case 7: cout << "seventy"; break;
	case 8: cout << "eighty"; break;
	case 9: cout << "ninty"; break;
	default: cout << ""; break;
	}

	switch (a % 10)
	{
	case 1: cout << " one" << endl; break;
	case 2: cout << " two" << endl; break;
	case 3: cout << " three" << endl; break;
	case 4: cout << " four" << endl; break;
	case 5: cout << " five" << endl; break;
	case 6: cout << " six" << endl; break;
	case 7: cout << " seven" << endl; break;
	case 8: cout << " eight" << endl; break;
	case 9: cout << " nine" << endl; break;
	default: cout << endl; break;
	}
	
	return 0;
}
