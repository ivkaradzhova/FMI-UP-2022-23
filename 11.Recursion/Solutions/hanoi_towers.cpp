#include <iostream>

void arrange_hanoi_towers(int n, char* from, char* to, char* extra) {
    if (n == 1) {
        std::cout << "Move disk from " << from << " to " << to <<std::endl;
        return;
    }

    arrange_hanoi_towers(n - 1, from, extra, to);
    std::cout << "Move disk from " << from << " to " << to <<std::endl;
    arrange_hanoi_towers(n - 1, extra, to, from);
    
}

int main() {
    int n;
    std::cin >> n;
    char a[] = "A";
    char b[] = "B";
    char c[] = "C";

    arrange_hanoi_towers(n, a, c, b);
    return 0;
}