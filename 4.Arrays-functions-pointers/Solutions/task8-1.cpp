#include <iostream>
#include <limits.h>

int addition(const int first_num, const int second_num)
{
    if ((first_num > 0 && first_num > INT_MAX - second_num) // first_num + second_num would be bigger than INT_MAX
        || (first_num < 0 && first_num < INT_MIN - second_num)) { // first_num + second_num would be smaller than INT_MIN
        throw std::exception("Error: The result of the addtion would be out of int limits\n");
    }

    return first_num + second_num;
}

int main()
{
    int some_num1, some_num2, result;
    std::cin >> some_num1 >> some_num2;

    try {
        result = addition(some_num1, some_num2);

        std::cout << "The result is "
            << result << std::endl;
    }

    catch (const std::exception& e) {
        std::cout << "Exception occurred" << std::endl
            << e.what() << std::endl;
    }
    return 0;
}
