#include <iostream>
#include <cmath>

//THIS PROGRAM SHOW USE OF POINTERS IN FUNCTION

//Function Prototype
void imag_real(double r, double theta, double* p_x, double* p_y);

//Main Function
int main(int argc, char *argv[])
{
    double r = 5.0;
    double theta = M_PI/3.0;
    double x,y;

    // NOTE: Reference variables addresses are called
    imag_real(r,theta,&x,&y);

    std::cout << "Real Part, x = " << x << std::endl;
    std::cout << "Imaginery Part, y = " << y << std::endl;


    return 0;
}

void imag_real(double r, double theta, double* p_x, double* p_y)
{
    *p_x = r*cos(theta);
    *p_y = r*sin(theta);
}