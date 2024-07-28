#include <iostream>
#include <cmath>

   //Problem 3
   // using Newton-Raphson Method to find solution on an equation

   double epsilon = 0.001; //xprev[] = {}, xnext[] = {};

   double func(double x)
   {
        return exp(x) + pow(x,3) - 5;
   }

    double derFunc(double x)
    {
        return exp(x) + 3*pow(x,2);
    } 

    //Test Case
    
    int main(int argc, char *argv[])
    {
        double x = 0.0; //Initial Guess
        bool solver = true;

        while(solver)
        {
            for(int i = 0; i <= 100; i++)
                {   
                    double h = func(x)/derFunc(x);

                    if (derFunc(x) == 0.0)
                    {
                        std::cout<<"The solution cannot proceed, as Division by zero is not allowed" << std::endl;

                    }

                    //Newton Raphson Method

                    x = x - func(x)/derFunc(x);

                    std::cout << "Iteration: " << i << " Value of X: " << x << " Value of h: " << h << std::endl;

                    if (std::abs(h) <= epsilon)
                    {
                        solver = false;
                        break;
                    }
                    
                }

        }

        std::cout <<"\n The Approximate Root is: " << x << std::endl;

        return 0;
    }