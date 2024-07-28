#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    const int arraySize = 7;
    std::string parameter[arraySize];
    double value[arraySize];

    // Open the file for Reading
    std::ifstream read_data("Parameters.txt");

    // Check if the file is open
    if (!read_data.is_open()) {
        std::cerr << "Error opening file for reading!" << std::endl;
        return 1;
    }

    // Reading from Files
    std::string line;
    for (int i = 0; i < arraySize && std::getline(read_data, line); i++) {
        std::istringstream iss(line);
        if (!(iss >> parameter[i] >> value[i])) {
            std::cerr << "Error reading from file!" << std::endl;
            read_data.close();
            return 1;
        }
    }

    // Close the file
    read_data.close();

    // Print the read values
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Parameter: " << parameter[i] << "\tValue: " << value[i] << std::endl;
    }

    return 0;
}
