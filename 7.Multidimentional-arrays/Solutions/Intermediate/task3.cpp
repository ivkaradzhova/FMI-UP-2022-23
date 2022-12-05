#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void move_tom(int size, int& x, int& y) {
    if (x < size - 1 && y < size - 1) {
        x++;
        y++;
    } else if (y == size - 1 && x == 0) {
        x = size - 1;
        y = 0;
        return;
    } else if (y == size - 1 && x <= size - 1) {
        y = (y - x) + 1;
        x = 0;
        
    } else if (x == size - 1 && y < size - 1) {
        x = (x - y) - 1;
        y = 0;
        
    }
    
}

int main() {
    const int MAX_SIZE = 10;
    int n, table[MAX_SIZE][MAX_SIZE] = {0};

    int counter = 0, tom_x, tom_y, jerry_x, jerry_y;

    std::cin >> n;
    std::cin >> tom_x >> tom_y;
    std::cin >> jerry_x >> jerry_y;

    table[tom_x][tom_y] = 0;

    while(tom_x != jerry_x || tom_y != jerry_y) {
        move_tom(n, tom_x, tom_y);
        counter++;
        table[tom_x][tom_y] = counter;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << table[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << counter << std::endl;
    return 0;
}