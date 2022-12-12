#include <iostream>
#include <cstring>
const int MAX_SIZE = 1024;

int find_first_occurrence(char* arr, char* target) {
    int i = 0;
    int target_length = strlen(target), string_length = strlen(arr);
    while(*arr != '\0' && strncmp(arr, target, target_length) != 0) {
        arr++;
        i++;
    }
    if (i >= string_length) {
        return -1;
    }
    return i;
}


void replace_substring(char* string, char substring[], char replacement[], char* result) {
    int substring_len = strlen(substring), replacement_length = strlen(replacement);

    int index =  find_first_occurrence(string, substring);
   
    while(index != -1) {
        strncpy(result, string, index);
        result += index;
        string += index; 

        strncpy(result, replacement, replacement_length);
        result += replacement_length;
        string += substring_len;
        
        index = find_first_occurrence(string, substring);
    }
    strncpy(result, string, strlen(string));
}

int main() {
    char string[MAX_SIZE] = "asdfgsdhasdqwesd", substring[MAX_SIZE]="sd", replacement[MAX_SIZE]="123", result[MAX_SIZE] = "";

    replace_substring(string, substring, replacement, result);

    std::cout << result;
    return 0;
}
