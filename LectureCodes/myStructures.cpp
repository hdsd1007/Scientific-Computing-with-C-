#include <iostream>
#include <cmath>


// Structure 
struct complex{
    float real;
    float imag;
};

// User-defined Functions
complex addComplex(complex c1, complex c2);

int main (int argc, char *argv[])
{
    complex c1, c2, c3;
    char signComplex;

    std::cout << "Enter the 1st Complex Number : " << std::endl;
    std::cin >> c1.real >> c1.imag;

    std::cout << "Enter the 2st Complex Number : " << std::endl;
    std::cin >> c2.real >> c2.imag;

    c3 = addComplex(c1, c2);
    signComplex = (c3.imag > 0) ? '+' : '-'; // Code to take into account sign of imaginary number

    std::cout << "Sum : " << c3.real << " " << signComplex << " " << fabs(c3.imag) << "i" << std::endl;

    return 0;
}


complex addComplex(complex c1, complex c2)
{
    complex temp;
    temp.real = c1.real + c2.real;
    temp.imag = c1.imag + c2.imag;

    return temp;
}