#include <iostream>

float division(float num, float den)
{
    if (den == 0) {
        throw std::exception("Math error: Attempted to divide by Zero\n");
    }

    return (num / den);

}

int main()
{
    float numerator, denominator, result;
    numerator = 12.5;
    denominator = 0;

    try {
        result = division(numerator, denominator);

        std::cout << "The quotient is "
            << result << std::endl;
    }

    catch (const std::exception e) {
        std::cout << "Exception occurred" << std::endl
            << e.what() << std::endl;
    }
    return 0;
}
