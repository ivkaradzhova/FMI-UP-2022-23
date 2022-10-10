#include <iostream>
using namespace std;

int main() {
    long egn;
    cin >> egn;

    int day, month, year;
    day = (egn / 10000) % 100;
    month = (egn / 1000000) % 100;
    year = (egn / 100000000) % 100;

    int month_first_number = month / 10;
    if (month_first_number == 4 | month_first_number == 5) {
        month -= 40;
        year += 2000;
    } else if (month_first_number == 2 | month_first_number == 3) {
        month -= 20;
        year += 1800;
    } else {
        year += 1900;
    } 

    cout << day << "." << month << "." << year << endl;

    return 0;
}