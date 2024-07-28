//Code Explaining the use of Function Template for Sorting Algorithm    
#include <iostream>

template<typename T>
void func_swap(T &arg1, T &arg2)
{
    T temp;
    temp = arg1;
    arg1 = arg2;
    arg2 = temp;
}

int main(int argc, char *argv[])
{

    int num1 = 10, num2 = 44;
    double d1 = 102.33, d2 = 23.33;
    char ch1 = 'A', ch2 = 'Z';

    std::cout << "Original Data" << std::endl;
    std::cout << " num1 = " << num1 << " , num2 = " << num2 << std::endl;
    std::cout << " d1 = " << d1 << " , d2 = " << d2 << std::endl;
    std::cout << " ch1 = " << ch1 << " , ch2 = " << ch2 << std::endl;

    func_swap(num1, num2);
    func_swap(d1, d2);
    func_swap(ch1, ch2);

    std::cout << "After Function Swap" << std::endl;
    std::cout << " num1 = " << num1 << " , num2 = " << num2 << std::endl;
    std::cout << " d1 = " << d1 << " , d2 = " << d2 << std::endl;
    std::cout << " ch1 = " << ch1 << " , ch2 = " << ch2 << std::endl;

    return 0;
}