//This code uses Newton-Raphson Method to solve Non-linear equation using Function Pointers
#include <iostream>
#include <cmath>

//Function Prototype for Second Order NL Equation
double Sqx(double x);
double dSqx(double x);

//Function Prototype for Third Order NL Equation
double Cbx(double x);
double dCbx(double x);

//Function Prototype NewtonRaphson
double NewtonRaphson(double (*pfunc)(double), double (*pdfunc)(double), double x);

//Main Function
int main(int argc, char* argv[])
{
    double a = 1.3, b = -2;

    //Solution for 2nd Order NL
    std::cout <<"The roots for the equation sqrt(x) - 2.7 = 0, with initial guess of " << a << " is " << NewtonRaphson(Sqx,dSqx,a) << std::endl;

    //Solution for 2nd Order NL
    std::cout <<"The roots for the equation 3x**3 - 15.625 = 0, with initial guess of " << b << " is " << NewtonRaphson(Cbx,dCbx,b) << std::endl;

    return 0;
}


//Functions 2nd Order NL
double Sqx(double x)
{
    return sqrt(x) - 2.7;
}
double dSqx(double x)
{
    return 1.0/(2.0*sqrt(x));
}


//Functions 3rd Order NL
double Cbx(double x)
{
    return x*x*x - 15.625;
}
double dCbx(double x)
{
    return 3*x*x;
}

//NewtonRaphson Function 
// The functions are passed as arguments using Pointers (*), the last arg is intial guess
double NewtonRaphson(double (*pfunc)(double), double (*pdfunc)(double), double x)
{
    double h;
    do{
        h = (*pfunc)(x)/(*pdfunc)(x);
        x -= h;
    }while(fabs(h) > 1.0e-6);
    return x;
}