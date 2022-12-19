#include <iostream>
#include <cstring>

const int MAX_SIZE = 1024;

int get_index_in_arr(char arr[][MAX_SIZE], int size, char string[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], string) == 0) {
            return i;
        }
    }
    return -1;
}

bool is_letter(char symbol) {
    return (symbol >= 'a' && symbol <= 'z') ||
            (symbol >= 'A' && symbol <= 'Z');
}

//returns a pointer to the start of the next word
char* skip_whitespace(char* sentence) {
    while(*sentence != '\0' && !is_letter(*sentence)) {
        sentence++;
    }
    return sentence;
}

void add_word_to_dictionary(char dictionary[][MAX_SIZE], int& num_words, int word_count[MAX_SIZE], char current_word[]) {
    int word_index = get_index_in_arr(dictionary, num_words, current_word);

    if (word_index != -1) {
        word_count[word_index]++;
    } else {
        // add a new word to the dictionary;
        strcpy(dictionary[num_words], current_word);
        num_words++;
        word_count[num_words]++;
    }
}

void word_histogram(char* sentence, char dictionary[][MAX_SIZE], int word_count[], int& num_words) {
    while (*sentence != '\0') {
    sentence = skip_whitespace(sentence);
    char current_word[MAX_SIZE] = "";
    int letter_index = 0;

    while (is_letter(*sentence)) {
        current_word[letter_index] = *sentence;
        letter_index++;
        sentence++;
    }
    add_word_to_dictionary(dictionary, num_words, word_count, current_word);
}
}

int find_most_repetitions(char dictionary[][MAX_SIZE], int& num_words, int word_count[MAX_SIZE]) {
    int max = 0, index = -1;

    for(int i = 0; i < num_words; i++) {
        if (max < word_count[i]) {
            max = word_count[i];
            index = i;
        }
    }

    return index;
}

char* most_occurences(char* sentence) {
    char dictionary[MAX_SIZE][MAX_SIZE], *sentence_copy = sentence;
    int word_count[MAX_SIZE] = {0};
    int num_words = 0;

    word_histogram(sentence, dictionary, word_count, num_words);

    int most_repetitions = find_most_repetitions(dictionary, num_words, word_count);
    if (most_repetitions == -1) {
        return nullptr;
    } else {
        return strstr(sentence, dictionary[most_repetitions]);
    }
}

int main() {
    char sentence[MAX_SIZE];
    std::cin.getline(sentence, MAX_SIZE);

    std::cout << most_occurences(sentence) << std::endl;

    return 0;
}
