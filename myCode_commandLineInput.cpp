#include <iostream>
#include <cmath>
#include <cstdlib> // used for command Line input

int main(int argc, char *argv[])
{

    //The code requires the user to input the number of nodes N, fluid density rho, dynamics viscosity mu, flow velocity U in the command line

    //Reading the command line input from the user and assigning them to the vairable with its data type

    //The counter for argv will start from 1 because the FIRST argument will be ./a.exe
    int number_of_nodes = atoi(argv[1]);
    double density = atof(argv[2]);
    double viscosity = atof(argv[3]);
    double velocity = atof(argv[4]);

    //Displaying the Variable

    std::cout << "Number of Nodes = " << number_of_nodes << std::endl;
    std::cout << "Density = " << density << std::endl;
    std::cout << "Dynamic Viscosity = " << viscosity << std::endl;
    std::cout << "Flow Velocity = " << velocity << std::endl;

    //Calculating the Reynolds Number based on the user input
    double ref_length = 1.0;

    //Calculating the Reynolds number
    double Reynolds_number = (density*velocity*ref_length)/viscosity;

    //Displaying the Reynolds Number
    std::cout << "The Reynolds number is  = " << Reynolds_number << std::endl;



    return 0;

}