//Code for understanding While Statement
#include <iostream>

int main(int argc, char *argv[])
{

    double z = 100.0;
    int count = 0;

    while(z > 1)
    {
        z *= 0.5; //Halving value of z at each loop

        count++; //Increasing the counter by 1

        std::cout <<"Value of z " << z << " and count is " << count << std::endl;

    }




    return 0;
}