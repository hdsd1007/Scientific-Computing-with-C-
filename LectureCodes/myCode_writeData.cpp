// This code deals with writing/reading data using FSTREAM header function

#include <iostream>
#include <fstream>
#include <cassert>

int main() {
    // Define the parameters
    int gridSize = 11;
    double stepSize = 1.0;

    // Open the file for writing
    std::ofstream outputFile("Square.txt");

    // Asserting whether the file is open
    assert(outputFile.is_open());

    
    // Write the coordinates to the file
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            double x = j * stepSize;
            double y = i * stepSize;
            outputFile << "(" << x << ", " << y << ") "; 
        }
        outputFile << std::endl;
    }

    // Close the file
    outputFile.close();

    std::cout << "Coordinates written to Square.txt successfully." << std::endl;

    return 0;
}