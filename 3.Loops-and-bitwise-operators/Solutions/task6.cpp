#include <iostream>
using namespace std;

int main() {
    int number, current_index = 0;
    bool result[32] = {0};
    cin >> number;
    
    while(number > 0) {
        result[current_index] = number % 2;
        current_index++;
        number /= 2;
    }

    for (int i = current_index - 1; i >= 0; i--) {
        cout << result[i];
    }
    cout << endl;
    return 0;
}