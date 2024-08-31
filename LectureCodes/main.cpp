#include "ComplexNumber.hpp"

int main(int argc, char *argv[])
{   

    ComplexNumber z1(1.6, -2.1);

    std::cout << "z1 = " << z1 << std::endl;
    std::cout << "Modulus z1 = " << z1.CalculateModulus() << std::endl;
    std::cout << "Argument z1 = " << z1.CalculateArgument() << std::endl;
    std::cout << "Complex Conjugate of z1 = " << z1.CalculateConjugate() << std::endl;

    ComplexNumber z2;
    z2 = z1.CalculatePower(3.0);
    std::cout << "z2 = z1*z1*z1 = " << z2 << std::endl;

    ComplexNumber z3;
    z3 = -z2;
    std::cout << "z3 = " << z3 << std::endl;

    ComplexNumber z4;
    z4 = z1 + z2;
    std::cout << "z1 + z2 = " << z4 << std::endl;

    ComplexNumber z_array[2];
    z_array[0] = z1;
    z_array[1] = z2;

    std::cout << "Second Element of z_array = " << z_array[1] << std::endl;

    //Assignment
    std::cout << "Real Part of z1 is " << z1.GetRealPart() << std::endl;
    std::cout << "Imaginary Part of z1 is " << z1.GetImaginaryPart() << "i" << std::endl;

    std::cout << "Real Part of z2 is " << z2.GetRealPart() << std::endl;
    std::cout << "Imaginary Part of z2 is " << z2.GetImaginaryPart() << "i" << std::endl;

    
    ComplexNumber z5;
    z5.SetToConjugate(z1);

    
    return 0;
}