#include <iostream>

const int MAX_SIZE = 10;

bool next_permutation(int n, int arr[]) {
    int i = n - 1;
    while(i >= 0 && arr[i] == n - 1) {
        arr[i] = 0;
        i--;
    }

    if (i >= 0) {
        arr[i]++;
        return true;
    }
    return false;
}

void print_queens(int n, int queen_column_indexes[]) {
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (j == queen_column_indexes[i]) {
                std::cout << "Q" << " ";
            } else {
                std::cout << "_" << " ";
            }
        }
        std::cout << std::endl;
    }
}

void generate_all_arrangments(int n) {
    int queen_column_indexes[MAX_SIZE] = {0};

    do {
        for(int i = 0; i < n; i++) {
            std::cout << queen_column_indexes[i] << " ";
        }
        std::cout << std::endl;
        print_queens(n, queen_column_indexes);
    } while(next_permutation(n, queen_column_indexes));
    
}

int main() {
    int n;

    std::cin >> n;

    generate_all_arrangments(n);
    return 0;
}