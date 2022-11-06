#include <iostream>
using namespace std;

int main() {
    int more_prevous = 0, previous = 1;
    int n, fn;

    cin >> n;

    if (n == 1) {
        fn = more_prevous;
    }

    if (n == 2) {
        fn = previous;
    } 

    for (int i = 3; i <= n; i++) {
        fn = previous + more_prevous;
        more_prevous = previous;
        previous = fn;
    }


    cout << fn << endl;

    return 0;
}