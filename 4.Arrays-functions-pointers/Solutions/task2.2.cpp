#include<iostream>
using namespace std;
void reverseArray(int size, char arr[]) {
    for(int i = 0; i < size / 2; i++) {
        char temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

char getHexDigit(int n) {
    switch (n) {
        case 0 ... 9: return '0' + n;
        case 10: return 'A'; 
        case 11: return 'B'; 
        case 12: return 'C'; 
        case 13: return 'D'; 
        case 14: return 'E'; 
        case 15: return 'F'; 
        default: return ' ';
    }
}

void toHexadecimal(int number, char hexNumber[], int& hexNumberLength) {
    hexNumberLength = 0;
    while(number > 0) {
        int remainder = number % 16;
        hexNumber[hexNumberLength] = getHexDigit(remainder);
        hexNumberLength++;
        number /= 16;
    }
    
    reverseArray(hexNumberLength, hexNumber);
}

int main() {
    int numberBase10, hexNumberLenght;
    char hexRepresentation[8];

    std::cin >> numberBase10;

    toHexadecimal(numberBase10, hexRepresentation, hexNumberLenght);

    for(int i = 0; i < hexNumberLenght; i++) {
        std::cout << hexRepresentation[i];
    }
    return 0;
}