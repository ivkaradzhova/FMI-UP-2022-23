#include <iostream>
using namespace std;

int main() {
    int prev_number, number;

    cin >> number;
    
    do {
        prev_number = number;
        cin >> number;
    } while(prev_number < number); 

    return 0;
}