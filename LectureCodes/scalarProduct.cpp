// Computing Scalar Product Using Dynamic Vector Allocation

#include <iostream>

// Scalar Product Function Prototype
double compute_scalar(double* a, double* b, int size);

int main(int argc, char *argv[])
{
    int size = 3;
    double* x = new double [size];
    double* y = new double [size];
    double dotProduct;

    for(int i = 0; i < size; i++)
    {
        x[i] = 1.0;
        y[i] = 2.0;
    }

    dotProduct = compute_scalar(x,y,size);

    std::cout << "The dot product is " << dotProduct << std::endl;
    
    return 0;

}

double compute_scalar(double* a, double* b, int size)
{
    double scalar_product(0.0);

    for(int i = 0; i < size; i++)
    {
        scalar_product += a[i]*b[i];
    }

    return scalar_product;
}