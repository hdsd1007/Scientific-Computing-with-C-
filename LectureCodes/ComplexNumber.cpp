//STORING ALL CONSTRUCTORS AND MEMBER FUNCTIONS

#include "ComplexNumber.hpp"
#include <cmath>


//Constructor to Override Default Constructor
ComplexNumber::ComplexNumber()
{
    mreal = 0.0;
    mimag = 0.0;
}

//Constructor to assign real and imag values
ComplexNumber::ComplexNumber(double x, double y)
{
    mreal = x;
    mimag = y;
}

//Function to Calculate Modulus of the Complex Numbers
double ComplexNumber::CalculateModulus() const
{
    return sqrt(mreal*mreal + mimag*mimag);

}

//Function to Calculate Argument of the Complex Numbers
double ComplexNumber::CalculateArgument() const
{
    return atan2(mimag,mreal);
}

//Function to Calculate Power of the Complex Numbers. NOTE the return type is complex, hence this is a UDF ComplexNumber unlike double for last two
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
    myReal modulus = CalculateModulus();
    myReal argument = CalculateArgument();

    myReal mod_of_result = pow(modulus, n);
    myReal arg_of_result = argument*n;

    myReal real_part = mod_of_result*cos(arg_of_result);
    myReal imag_part = mod_of_result*sin(arg_of_result);

    ComplexNumber z(real_part, imag_part);

    return z;

}

// Overloading the Assignment '=' Operator
ComplexNumber& ComplexNumber::operator=(const ComplexNumber &z)
{
    mreal = z.mreal;
    mimag = z.mimag;
    return *this;
}

//Overloading Unary Subtraction Operator (Negate)
ComplexNumber ComplexNumber::operator-() const
{
    ComplexNumber w;
    w.mreal = -mreal;
    w.mimag = -mimag;
    return w;
}

//Overloading Binary Addition Operator
ComplexNumber ComplexNumber::operator+(const ComplexNumber &z) const
{
    ComplexNumber w;
    w.mreal = mreal + z.mreal;
    w.mimag = mimag + z.mimag;
    return w;
}

//Overloading Binary Subtraction Operator
ComplexNumber ComplexNumber::operator-(const ComplexNumber &z) const
{
    ComplexNumber w;
    w.mreal = mreal - z.mreal;
    w.mimag = mimag - z.mimag;
    return w;
}


//Overloading OutputStream
std::ostream& operator<<(std::ostream& output, const ComplexNumber &z)
{
    //Format as "x + yi" or as "x - yi" 
    output << "(" << z.mreal << " ";
    if(z.mimag >= 0)
        output << "+ " << z.mimag << "i)";
    else 
        output << "- " << -z.mimag << "i)";

    return output;
}


//ASSIGNMENT TASK

//Method Function to get access private and imaginary part
myReal ComplexNumber::GetRealPart() const
{
    return mreal;
}

myReal ComplexNumber::GetImaginaryPart() const
{
    return mimag;
}

//Friend Function
myReal RealPart(const ComplexNumber& z)
{
    return z.mreal;
}

myReal ImaginaryPart(const ComplexNumber& z)
{
    return z.mimag;
}

//Method to find conjugate
ComplexNumber ComplexNumber::CalculateConjugate()
{
    ComplexNumber w;
    w.mreal = mreal;
    w.mimag = -mimag;

    return w;
}

void ComplexNumber::SetToConjugate(const ComplexNumber& z)
{
    ComplexNumber w;
    w.mreal = z.mreal;
    w.mimag = -z.mimag;

    std::cout << "(" << w.mreal << " " << w.mimag << "i)" << std::endl;

}