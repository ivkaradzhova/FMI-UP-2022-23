#include <iostream>
using namespace std;

int main() {
    char letter;
    const int lower_upper_case_diff = 'a' - 'A';

    cin >> letter;

    cout << (char)(letter - lower_upper_case_diff) << endl;

    return 0;
}