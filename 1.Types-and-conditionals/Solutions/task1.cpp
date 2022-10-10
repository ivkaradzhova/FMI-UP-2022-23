#include <iostream>
using namespace std;

int main() {
    const double pi = 3.14;
    int r, h;

    cin >> r >> h;

    float surface_area = 2 * pi * r * (r + h);
    cout << surface_area << endl;

    return 0;
}