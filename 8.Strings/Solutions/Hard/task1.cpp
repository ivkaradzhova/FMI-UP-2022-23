#include <iostream>
#include <cstring>
const int MAX_SIZE = 1024;

bool array_contains_string(char arr[][MAX_SIZE], int size, char string[]) {
    for(int i = 0; i < size; i++) {
        if(strcmp(arr[i], string) == 0) {
            return true;
        }
    }
    return false;
}

void read_directories(char file_path[], char result[][MAX_SIZE], int& cur_num_dirs) {
    int curr_index = 0;
    while(file_path[curr_index] != '\0') {
        if (file_path[curr_index] == '/') {
            char curr_path[MAX_SIZE] = "";
            strncpy(curr_path, file_path, curr_index + 1);
            
            if(!array_contains_string(result, cur_num_dirs, curr_path)) {
                strcpy(result[cur_num_dirs], curr_path);
                cur_num_dirs++;
            }
        }
        curr_index++;
    }
}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    char arr[MAX_SIZE][MAX_SIZE], all_dirs[MAX_SIZE][MAX_SIZE];
    int num_all_dirs = 0;
    
    for(int i = 0; i < n; i++) {
        std::cin.getline(arr[i], MAX_SIZE);
    }

    for(int i = 0; i < n; i++) {
        read_directories(arr[i], all_dirs, num_all_dirs);
    }
    for(int i = 0; i < num_all_dirs; i++) {
     
        std::cout << all_dirs[i] << std::endl;
    }
    return 0;
}