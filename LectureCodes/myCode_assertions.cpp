#include <iostream>
#include <cmath>
#include <cassert>

// Code finds the square root of the sum of three numbers

int main(int argc, char *argv[])
{
    // Prompt user for an input X, Y and Z

    double X,Y,Z;
    double sum;

    std::cout << "Enter three random postive or negative numbers: " << std::endl;
    std::cin >> X >> Y >> Z;

    sum = X + Y + Z;

    assert(sum >= 0.0);

    std::cout << "The square root of sum of the numbers are " << sqrt(sum) << std::endl;


    return 0;
}