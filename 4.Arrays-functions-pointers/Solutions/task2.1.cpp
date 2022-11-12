#include<iostream>


void reverseArray(int size, bool arr[]) {
    for(int i = 0; i < size / 2; i++) {
        bool temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}


void toBinary(int number, bool binaryNumber[], int& binaryNumberLength) {
    binaryNumberLength = 0;
    while(number > 0) {
        binaryNumber[binaryNumberLength] = number % 2;
        binaryNumberLength++;
        number /= 2;
    }
    
    reverseArray(binaryNumberLength, binaryNumber);
}


int main() {
    int numberBase10, binaryNumberLenght;
    bool binaryRepresentation[32] = {0};

    std::cin >> numberBase10;

    toBinary(numberBase10, binaryRepresentation, binaryNumberLenght);

    for(int i = 0; i < binaryNumberLenght; i++) {
        std::cout << binaryRepresentation[i];
    }
    return 0;
}