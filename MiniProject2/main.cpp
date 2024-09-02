//Main File for Matrix Class
#include "Matrix.hpp"

int main(int argc, char *argv[])
{

    Matrix M1(3,3);

    std::cout << "Matrix M1 created." << std::endl;

    for(int i = 1; i <= M1.GetRows(); i++)
    {
        for(int j = 1; j <= M1.GetCols(); j++)
        {
            std::cout << M1(i,j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    //We are storing a random value in the vector to see if it can be accessed through round brackets
    M1(1,1) = 13.2; M1(1,2) = 23; M1(2,2) = 121;
    
    //Printing the Matrix again
    for(int i = 1; i <= M1.GetRows(); i++)
    {
        for(int j = 1; j <= M1.GetCols(); j++)
        {
            std::cout << M1(i,j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Testing the Overloaded Output Parameter
    std::cout << "Matrix M1 using overloaded output parameter " << std::endl;
    std::cout << M1 << std::endl;

    // Basic Matrix Manipulation
    Matrix A(3, 3), B(3, 3);
    
    //Making A Identity Vector
    A(1,1) = 1; A(2,2) = 1; A(3,3) = 1;
    B = -A;

    //Printing Matrix A and B
    std::cout << "Matrix A is " << std::endl;
    std::cout << A << std::endl;
    std::cout << "Matrix B is " << std::endl;
    std::cout << B << std::endl;

    double k = 2;
    Matrix E = A*k;
    Matrix F = B*3.14;

    //Printing each Matrix C,D,E
    std::cout << "Matrix E = A * 2 is " << std::endl;
    std::cout << E << std::endl;
    std::cout << "Matrix F = B * 3.14 is " << std::endl;
    std::cout << F << std::endl;

    Matrix C = E + F;
    Matrix D = F * C;

    //Printing each Matrix C,D,E
    std::cout << "Matrix C = E + F is " << std::endl;
    std::cout << C << std::endl;
    std::cout << "Matrix D = C * F is " << std::endl;
    std::cout << D << std::endl;


    //Calculating the determinant of the Martix C and D
    double det_C = C.CalculateDet();
    std::cout << "Determinant of Matrix C is " << det_C << std::endl;
    double det_D = D.CalculateDet();
    std::cout << "Determinant of Matrix D is " << det_D << std::endl;
    std::cout << std::endl;

    std::cout << "Program ending." << std::endl;
    return 0;
}