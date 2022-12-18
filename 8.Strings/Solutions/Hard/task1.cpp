#include <iostream>
#include <cstring>

const int MAX_SIZE = 1024;
const char FILE_SEPERATOR = '/';
const char DOT = '.'; 

bool validate_path(char file_path[]) {
    int length = strlen(file_path);

    // check for dir1/dir2
    if (length > 0 && file_path[0] != FILE_SEPERATOR) {
        std::cout << "File path " << file_path << " doesn't start with /" << std::endl;
        return false;
    }

    //check for /dir1//dir2
    for (int i = 1; i < length; i++) {
        if ((file_path[i] == FILE_SEPERATOR) && file_path[i - 1] == FILE_SEPERATOR) {
            std::cout << "File path " << file_path << " contains empty directory names" << std::endl;
            return false;
        }
    }
    
    //check for /dir1/file1.txt/dir2
    char* dot_occurence = strchr(file_path, DOT);

    if (dot_occurence != nullptr && strchr(dot_occurence, FILE_SEPERATOR) != nullptr) {
        std::cout << "File path " << file_path << " contains empty a file with a subdirectory" << std::endl;
        return false;
    }

    return true;
}

bool array_contains_string(char arr[][MAX_SIZE], int size, char string[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], string) == 0) {
            return true;
        }
    }
    return false;
}

bool is_file(char file_path[]) {
    return strchr(file_path, DOT) != nullptr;
}

void add_directory(char file_path[], char dirs_list[][MAX_SIZE], int& number_of_dirs) {
    if(!is_file(file_path) && !array_contains_string(dirs_list, number_of_dirs, file_path)) {
        strcpy(dirs_list[number_of_dirs], file_path);
        number_of_dirs++;
    }
}

void separate_directories(char file_path[], char dirs_in_file_path[][MAX_SIZE], int& number_of_dirs) {
    int curr_index = 0;

    while (file_path[curr_index] != '\0') {
        if (file_path[curr_index] == FILE_SEPERATOR) {
            // add the newly discovered path to the list of directories - dirs_in_file_path,
            // if it is not there already
            char curr_path[MAX_SIZE] = "";
            strncpy(curr_path, file_path, curr_index);
            add_directory(curr_path, dirs_in_file_path, number_of_dirs);
        }
        curr_index++;
    }

    // add the path to the last directory (after the last '/')
    if (file_path[curr_index - 1] != '/') {
        char curr_path[MAX_SIZE] = "";
        strcpy(curr_path, file_path);
        add_directory(curr_path, dirs_in_file_path, number_of_dirs);
    }

}

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    assert(n < MAX_SIZE);

    char arr[MAX_SIZE][MAX_SIZE], all_dirs[MAX_SIZE][MAX_SIZE];
    int num_all_dirs = 0;
    for (int i = 0; i < n; i++) {
        std::cin.getline(arr[i], MAX_SIZE);
        
        if (!validate_path(arr[i])) {
            std::cout << "Validation failed" << std::endl;
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        separate_directories(arr[i], all_dirs, num_all_dirs);
    }


    for (int i = 0; i < num_all_dirs; i++) {
        std::cout << all_dirs[i] << std::endl;
    }
    return 0;
}