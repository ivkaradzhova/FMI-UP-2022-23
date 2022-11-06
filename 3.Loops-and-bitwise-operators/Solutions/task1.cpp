#include <iostream>
using namespace std;

int main() {
    int a, b;

    cin >> a >> b;

    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    while (a % b != 0) {
        int temp_a = a;
        a = b;
        b = temp_a % b;
    }

    cout << b << endl;

    return 0;
}