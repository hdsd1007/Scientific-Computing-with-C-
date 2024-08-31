// Module 6 Writing CLass and Objects

#include <iostream>

// Class for Complex Number Additions

class Complex
{
    public: // Access Specifiers

    double real, imag; // Data Variables

        Complex add_complex(Complex c1, Complex c2){
            // Member Functions
            Complex temp;

            temp.real = c1.real + c2.real;
            temp.imag = c1.imag + c2.imag;

            return temp;
        }
};


int main(int argc, char* argv[])
{
    Complex c1 = {5.2, 3.3};
    Complex c2 = {1.2, 11.3};

    Complex c3;
    c3 = c3.add_complex(c1,c2);

    std::cout << "Complex Number 1: " << c1.real << " + i" << c1.imag << std::endl;
    std::cout << "Complex Number 2: " << c2.real << " + i" << c2.imag << std::endl;
    std::cout << "Complex Number 3: " << c3.real << " + i" << c3.imag << std::endl;

    return 0;
}