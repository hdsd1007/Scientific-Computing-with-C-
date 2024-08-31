//Program to Find minimum and maximum using Friend Function
#include <iostream>
#include "friendFunc.cpp"

int main(int argc, char *argv[])
{
    ExampleClass work(6.9, 5.6);

    std::cout << "Minimum : " << work.get_minimum() << std::endl;
    std::cout << "Maximum : " << get_maximum(work) << std::endl;

    return 0;
}