#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double initial_price, new_price, difference;

	cin >> initial_price >> new_price;

	difference = new_price - initial_price;

	cout << setprecision(2) << showpoint << fixed; 

	if (difference > 0) {
		
		cout << "The price has risen with " << difference << " lv." << endl;

		return 0;
	}

	cout << "The price has gone down with " << -difference << " lv." << endl;
	return 0;
}
