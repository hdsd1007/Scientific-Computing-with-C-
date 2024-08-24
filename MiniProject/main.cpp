#include <iostream>
#include "Vector.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Default Initialization for V1 \n";
    Vector V1(3);
    for(int i = 0; i < V1.GetSize(); i++)
        std::cout << V1[i] << " ";
    std::cout << std::endl;

    std::cout << "Making V1 a Unit Vector along X1" << std::endl;
    V1[0] = 1.0;
    for(int i = 0; i < V1.GetSize(); i++)
    {
        std::cout << V1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Calling Copy Constructor, V2 is a copy of V1" << std::endl;
    Vector V2(V1);
    for(int i = 0; i < V2.GetSize(); i++)
    {
        std::cout << V2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Making V2 a unit vector along X2" << std::endl;
    V2[0] = 0.0;
    V2[1] = 1.0;
    for(int i = 0; i < V2.GetSize(); i++)
    {
        std::cout << V2[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Creating a V3 with the same size as V1" << std::endl;
    // NOTE: The code below only creates Vector V3 of size V1 and does not copy the constructor
    Vector V3(V1.GetSize());
    for(int i = 0; i < V3.GetSize(); i++)
    {
        std::cout << V3[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Making V3 a unit vector X3" << std::endl;
    V3[2] = 1.0;
    for(int i = 0; i < V3.GetSize(); i++)
    {
        std::cout << V3[i] << " ";
    }
    std::cout << std::endl;

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
    for(int i; i < V4.GetSize(); i++)
    {
        std::cout << V4[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Testing the Binary(+) Operator" << std::endl;
    std::cout << "Creating Matrix V4 = V1 + V3" << std::endl;
    V4 = V1 + V3;
    for(int i; i < V4.GetSize(); i++)
    {
        std::cout << V4[i] << " ";
    }
    std::cout << std::endl;   

    std::cout << "Testing the Binary(-) Operator" << std::endl;
    std::cout << "Creating Matrix V4 = -V1 - V2 - V3" << std::endl;
    V4 = -V1 - V2 - V3;
    for(int i; i < V4.GetSize(); i++)
    {
        std::cout << V4[i] << " ";
    }
    std::cout << std::endl;      
    

    return 0;
}