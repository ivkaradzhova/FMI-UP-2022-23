#include <iostream>
using namespace std;
int numberOfRepetitions(int number, int arr[], int size) {
    int repetitions = 0;
    for(int i = 0; i < size; i++) {
        if(arr[i] == number) {
            repetitions++;
        }
    }

    return repetitions;
}

bool arrayContainsNumber(int number, int arr[], int size) {
    int i = 0;
    // if itteration over an array with a while loop
    // always check if the index is not out of bound FIRST 
    // and then add any other assertions!
    while(i < size && arr[i] != number) {
        i++;
    }
    
    return i != size;
}

int main() {
    const int MAX_ARR_SIZE = 1000;
    int n, arr[MAX_ARR_SIZE];
    int result[MAX_ARR_SIZE], index = 0;

    std::cin >> n;
    assert(n < MAX_ARR_SIZE);

    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int maxRepetitions = 0;
    for(int i = 0; i < n; i++) {
        int repetitions = numberOfRepetitions(arr[i], arr, n);
        if(maxRepetitions < repetitions) {
            index = 0;
            result[index] = arr[i];
            maxRepetitions = repetitions;
            index++;
        }
        
        if(maxRepetitions == repetitions && !arrayContainsNumber(arr[i], result, n)) {
            result[index] = arr[i];
            index++;
        }
    }

    std::cout << "The numbers with the most repetitions are ";
    for (int i = 0; i < index; i++) {
        std::cout << result[i] << " ";
    }
    return 0;
}