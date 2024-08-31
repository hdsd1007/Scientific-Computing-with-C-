#include "2dMatrix.hpp"

int main(int argc, char *argv[])
{
    Matrix2d a(1,2,3,4);

    std::cout << "The Main Matrix is " << a << std::endl;
    std::cout << "The determinant of Matrix is " << a.CalculateDeterminant() << std::endl;
    std::cout << "Inverse Matrix:" << a.CalculateInverse() << std::endl;
    
    Matrix2d b;
    b = a;
    std::cout << "The  Matrix is b is " << b << std::endl;

    Matrix2d c;
    c = -a;
    std::cout << "The  Matrix is c is " << c << std::endl;

    Matrix2d d;
    d = a + b;
    std::cout << "The  Matrix is d is " << d << std::endl;

    Matrix2d A;
    A = a.MatrixMultiplier(2);
    std::cout << "The  Matrix is A is " << A << std::endl;


    return 0;
}