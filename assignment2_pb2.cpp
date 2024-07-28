#include <iostream>
#include <fstream>
#include <cmath>
#include <cassert>
#include <vector>

int main(int argc, char *argv[]){

    //Getting the number of grid points  from Command Line
    int N = atoi(argv[1]);

    //Assert that number of grid points greater than 1
    assert(N > 1);

    // Calculate Step Size
    double dx = 1.0 / (N - 1);

    //Open Solution File for output data
    std::ofstream output("Solution.dat");
    output.setf(std::ios::showpos);

    //Check whether the file is open
    assert(output.is_open());

    //Initialize the Vector
    std::vector<double> x(N),y(N);

    //Initial Condition
    x[0] = 0.0;
    y[0] = 1.0;

    //Implicit Backward Euler
    for (int n = 1; n < N; n++){
        x[n] = n * dx;
        y[n] = y[n - 1] / (1.0 + dx);
    }

    // Writing output to Solution.dat
    output << "x\ty" << std::endl;
    for (int i = 0; i < N; i++ ){
        output << x[i] << "\t" << y[i] << std::endl;
    }

    output.close();

    std::cout << "Solution data written to 'Solution.dat'." << std::endl;

    return 0;
}