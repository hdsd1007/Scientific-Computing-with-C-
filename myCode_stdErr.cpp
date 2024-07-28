// Program on Std::cerr Command
#include<iostream>
#include<cmath>

int main(int argc, char *argv[])
{
    double x, y;

    std::cout <<"Enter two random numbers: " << std::endl;
    std::cin >> x >> y;

    std::cout << "The sum of the numbers are \n";
    std::cout << x+y << std::endl;

    if(y == 0)
    {
        std::cerr << "Division by zero not allowed \n";
    }
    else
    {
        std::cout <<"Division is " << x/y << std::endl;
    }

    return 0;
}