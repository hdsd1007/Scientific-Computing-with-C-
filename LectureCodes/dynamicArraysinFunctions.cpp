// This code is about the use of arrays (dynamic) in functions

#include <iostream>


// Function Prototype
void dynamic_Array(double* a, double** b);


int main(int argc, char *argv[])
{

    double* x = new double[5];     // This is a 1D Matrix

    double** y = new double* [3]; // This allocates memory for the number of rows

    for(int i = 0; i<3; i++)
    {
        //Indexing in CPP begins with Zero
        // The below line specifies that the matrix Y will have 3 elements in each row
        y[i] = new double [3];

    }

    dynamic_Array(x,y);

    std::cout << "x[1] = " << x[1] << std::endl;
    std::cout << "y[1][1] = " << y[1][1] << std::endl;

    return 0;
}



void dynamic_Array(double* a, double** b)
{

    a[1] = 1.2;
    b[1][1] = 4.0;
}