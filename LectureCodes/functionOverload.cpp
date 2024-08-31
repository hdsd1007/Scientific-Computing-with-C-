//This code is regarding Function Overloading
#include <iostream>

// Function Prototype for multiplication of vector by a scalar
void multiply(double* vec1, double k1, double* vec2, int n);

// Funtion Prototype for multiplying a matrix by a scalar
void multiply(double** mat1, double k1, double** mat2, int n);

int main(int argc, char* argv[])
{
    int n = 3;
    double* vec1 = new double[n];
    double* vec2 = new double[n];

    //Initializing the Rows for matrix
    double** mat1 = new double* [n];
    double** mat2 = new double* [n];

    //Initializing the Columns for Matrix
    for(int i = 0; i < n; i++)
    {
        mat1[i] = new double [n];
        mat2[i] = new double [n];
    }

    //Vector
    vec1[0] = 2.1; vec1[1] = 4.1; vec1[2] = 6.1;

    //Matrix
    mat1[0][0] = 1.2;mat1[0][1] = 2.2;mat1[0][2] = 3.2;
    mat1[1][0] = 1.2;mat1[1][1] = 2.2;mat1[1][2] = 3.2;
    mat1[2][0] = 1.2;mat1[2][1] = 2.2;mat1[2][2] = 3.2;

    double k1 = 2.0; double k2 = 1.5;

    // Making use of Function

    //Vector Multiplication
    multiply(vec1,k1,vec2,n);

    std::cout << "Vector Scalar Multiplication: " << std::endl;

    for(int i = 0; i<n;i++)
    {
        std::cout << vec2[i] << " ";
    }
    std::cout << std::endl;

    //Matrix Multiplication
    multiply(mat1,k2,mat2,n);

    std::cout << "Matrix Scalar Multiplication: " << std::endl;

    for(int i = 0; i<n;i++){

        for(int j = 0; j<n;j++){

            {
                std::cout << mat2[i][j] << " ";
            }
            
        }

        std::cout << std::endl;
    }

    //Deleting/Emptying Matrix

    delete[] vec1;
    delete[] vec2;

    for(int i = 0; i < n; i++)
    {
        delete[] mat1[i];
        delete[] mat2[i];
    }

    delete[] mat1;
    delete[] mat2;

    return 0;
}

// Function Prototype for multiplication of vector by a scalar
void multiply(double* vec1, double k1, double* vec2, int n)
{
    // vec2 = k1*vec1

    for(int i = 0; i < n; i++)
    {
        vec2[i] = k1*vec1[i];
    }

}

// Funtion Prototype for multiplying a matrix by a scalar
void multiply(double** mat1, double k1, double** mat2, int n)
{
    // mat2 = k1*mat1

    for(int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            mat2[i][j] = k1*mat1[i][j];

        }
    }
}