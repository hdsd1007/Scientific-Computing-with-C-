// This code is for assignment 2
// TASK 1 and 2 //

#include <iostream>
#include <fstream>
#include <cassert>

int main(int argc, char *argv[])
{
    double x1[3] = {1.0, 0.0, 0.0};
    double x2[3] = {0.0, 1.0, 0.0};
    double x3[3] = {0.0, 0.0, 1.0};
    char answer;
    int numLines = 0;
    std::string line;


    // Using ifstream function to check whether the vector.dat exists or not
    // Asking user to delete or append the file if it exists
    std::ifstream B("vectors.dat");
    if(B.is_open()){
        B.close(); //File already exist
        std::cout << "File 'vectors.dat' already exist" << std::endl;

        std::cout << "Do you want to Append or Erase the existing data? Enter A for Appending or E for Erasing: " << std::endl;
        std::cin >> answer;

        if(answer == 'E'){
            //User decided to Erase the Data
            std::cout << "Erasing the Existing Data and Creating a new file" << std::endl;
        }
        else if (answer == 'A'){
            //User decides to Append the Data
            std::cout << "Appending to the Existing Data" << std::endl;
        }
        else {
            //Invalid Input
            std::cerr << "Invalid Input!" << std::endl;
            return 1; 
        }
    }
    else{
        // File vector.dat does not exist 
        std::cout << "Create new file 'vectors.dat'........" << std::endl;
    }

    //Create a vector output file based on the user input 
    std::ofstream A("vectors.dat", (answer == 'E') ? std::ios::out : std::ios::app);

    // Checking whether file is open 
    assert(A.is_open());

    // Changing out format to Scientific
    A.setf(std::ios::scientific);
    A.setf(std::ios::showpos);
    A.precision(8);

    //Loop to write data on a new line
    for(int i = 0; i < 1; i++){

        A << "x1 " << x1[i] << " " << x1[i+1] << " " << x1[i+2] << std::endl;
        A << "x2 " << x2[i] << " " << x2[i+1] << " " << x2[i+2] << std::endl;
        A << "x3 " << x3[i] << " " << x3[i+1] << " " << x3[i+2] << std::endl;
    }

    A.close();

    //Reading the number of line in the vectos.dat file
    std::ifstream C("vectors.dat");

    // Checking whether file is open 
    assert(C.is_open());

    while(std::getline(C, line)){
        numLines++;
    }

    C.close();

    std::cout << "Number of lines in the 'vector.dat': " << numLines << std::endl;

    return 0;
}