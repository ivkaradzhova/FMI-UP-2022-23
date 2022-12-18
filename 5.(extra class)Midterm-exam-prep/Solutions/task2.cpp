#include <iostream>

using namespace std;
const int ALPHABET_SIZE = 26, MAX_ARRAY_SIZE = 10000;

void generateAlphabet(char alphabet[]) {
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        alphabet[i] = 'a' + i;
    }
}

void arrayRotation(int key, char array[], int size) {
    char arrayCopy[MAX_ARRAY_SIZE];

    for(int i = 0; i < size; i++) {
        arrayCopy[i] = array[i];
    }

    for(int i = 0; i < size; i++) {
        array[i] = arrayCopy[(i + key) % size];
    }
}

int findIndex(int element, char array[], int size) {
    int index = 0;
    while(index < size && element != array[index]) {
        index++;
    }

    if (index != size) {
        return index;
    } else {
        return -1;
    }
}

void swapLetters(char msg[], int msgSize, char alphabet1[], char alphabet2[]) {
    for (int i = 0; i < msgSize; i++) {
        if(msg[i] != ' ') {
            int index = findIndex(msg[i], msg, msgSize);
            msg[i] = 
        }
    }
}

int main() {
    int n, key;
    char msg[MAX_ARRAY_SIZE], alphabet[ALPHABET_SIZE], cryptingAlphabet[ALPHABET_SIZE];
   
    cin >> n;

    for (int i = 0; i < n; i++) {
       cin >> msg[i];
    }

    generateAlphabet(alphabet);
    generateAlphabet(cryptingAlphabet);
    arrayRotation(key, cryptingAlphabet, ALPHABET_SIZE);

    

    for (int i = 0; i < 26; i++) {
       cout<<alphabet[i];
    }

    return 0;
}
