#include <iostream>

using namespace std;

unsigned int count_digits(unsigned int number) {
  unsigned int count = 1;
  number /= 10;
  while (number > 0) {
    count++;
    number /= 10;
  }

  return count;
}

// This usually is not a good practice - it's better to use 'delete'
// in the function where we use 'new' we should
char* number_to_string(unsigned int number) {
  unsigned int count = count_digits(number);
  char* result = new char[count + 1];

  result[count] = '\0';
  for(unsigned int i = 0; i < count; i++) {
    unsigned int digit = number % 10;
    number /= 10;
    result[count - i - 1] = '0' + digit;
  }

  return result;
}

int main() {
  unsigned int number = 120;

  char* string = number_to_string(number);

  cout << string << endl;

  delete[] string;  
  return 0;
}
