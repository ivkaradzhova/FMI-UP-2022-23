#include <iostream>
#define N 10000
using namespace std;

int gratest_common_divisor(int a, int b) {
    // switch places so a is always the bigger number
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
    return b;

} 

int main() {
    int number, prev_number;
   
    cin >> prev_number >> number;
    int gcd = gratest_common_divisor(prev_number, number);

    // we will allow new numbers till all of the numbers till now
    // have a common divisor. This means that the while loop should stop
    // when there is no longer a common divisor which is the same as the 
    // greatest common divisor being 1.
    while (gcd != 1) {
        cin >> number;
        gcd = gratest_common_divisor(gcd, number);  
    }
  
    return 0;
}