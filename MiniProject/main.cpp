#include <iostream>
#include "Vector.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Default Initialization for V1 \n";
    Vector V1(3);
    std::cout << "V1 = " << V1 << std::endl;

    std::cout << "Making V1 a Unit Vector along X1" << std::endl;
    V1[0] = 1.0;
    std::cout << "V1 = " << V1 << std::endl;

    std::cout << "Calling Copy Constructor, V2 is a copy of V1" << std::endl;
    Vector V2(V1);
    std::cout << "V2 = " << V2 << std::endl;


    std::cout << "Making V2 a unit vector along X2" << std::endl;
    V2[0] = 0.0;
    V2[1] = 1.0;
    std::cout << "V2 = " << V2 << std::endl;


    std::cout << "Creating a V3 with the same size as V1" << std::endl;
    // NOTE: The code below only creates Vector V3 of size V1 and does not copy the constructor
    Vector V3(V1.GetSize());
    std::cout << "V3 = " << V3 << std::endl;

    std::cout << "Making V3 a unit vector X3" << std::endl;
    V3[2] = 1.0;
    std::cout << "V3 = " << V3 << std::endl;

    std::cout << "\n Read-only Variant of []" << std::endl; // Zero Based Indexing
    std::cout << "V1(0) " << V1.Read(0);
    std::cout << " V1(1) " << V1.Read(1);
    std::cout << " V1(2) " << V1.Read(2);
    std::cout << std::endl;

    std::cout << "\n Read-only Variant of ()" << std::endl; // One Based Indexing
    std::cout << "V1(1) " << V1(1);
    std::cout << " V1(2) " << V1(2);
    std::cout << " V1(3) "  << V1(3);
    std::cout << std::endl;
    
    //Matrix Calculus Basics (Addition and Subtraction)
    std::cout << "Testing the Unary(-) Operator" << std::endl;
    std::cout << "Creating Matrix V4 = - V1" << std::endl;

    //Create new vector V4
    Vector V4 = -V1;
    std::cout << "V4 = " << V4 << std::endl;

    std::cout << "Testing the Binary(+) Operator" << std::endl;
    std::cout << "Creating Matrix V4 = V1 + V3" << std::endl;
    V4 = V1 + V3;
    std::cout << "V4 = " << V4 << std::endl;

    Vector V5(V1.GetSize());
    std::cout << "Testing the Binary(-) Operator" << std::endl;
    std::cout << "Creating Matrix V5 = -V1 - V2 - V3" << std::endl;
    V5 = -V1 - V2 - V3;
    std::cout << "V5 = " << V5 << std::endl;   

    std::cout << std::endl; 

    //Scalar and Dot Product Multiplication
    std::cout <<"Demonstrating the Scalar Multiplication" << std::endl;
    double k = 4;
    V5 = V5*k;
    //The operator used is the overloaded operator
    std::cout << "V5 = " << V5 << std::endl;

    std::cout <<"Demonstrating the Dot Product Multiplication" << std::endl;
    //The Output OPerator << is not the overloaded one
    std::cout << "V1.V2 = " << V1*V2 << std::endl;
    std::cout << "V4.V5 = " << V4*V5 << std::endl;

    std::cout << std::endl;

    Vector V6(3);
    V6[0] = 3; V6[1] = 7; V6[2] = 5;

    std::cout << V6 << std::endl;
    

    std::cout <<"Validating the use of p-Norm (L2) " << std::endl;
    //L2 Norm of Unit Vector Should be 1
    std::cout << "L2 norm of V1 = " << V1.CalculateNorm() << std::endl; 
    std::cout << "L2 norm of V2 = " << V2.CalculateNorm() << std::endl;
    std::cout << "L2 norm of V3 = " << V3.CalculateNorm() << std::endl;
    std::cout << "L2 norm of V6 = " << V6.CalculateNorm() << std::endl;

    std::cout << "Validating the use of p-Norm using different values" << std::endl;
    std::cout << "L3 norm of V1 = " << V1.CalculateNorm(3) << std::endl;
    std::cout << "L3 norm of V6 = " << V6.CalculateNorm(3) << std::endl;


    // Finding Unit Vector
    std::cout << "Validating the use of Unit Vector" << std::endl;
    Vector u1 = V1.UnitVector();
    std::cout << "The unit vector of V1 is " << u1 << std::endl;
     Vector u2 = V2.UnitVector();
    std::cout << "The unit vector of V2 is " << u2 << std::endl;
     Vector u6 = V6.UnitVector();
    std::cout << "The unit vector of V4 is " << u6 << std::endl;
  

    return 0;
}