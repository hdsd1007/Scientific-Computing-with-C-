#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  // Use vectors to store parameter names and values
  vector<string> parameter;
  vector<double> value;

  // Open the file for reading
  ifstream read_data("Parameters.txt");

  if (!read_data.is_open()) {
    cerr << "Error opening file Parameter.txt" << endl;
    return 1;
  }

  // Skip the header line (assuming there's one)
  string header;
  getline(read_data, header);

  // Read parameter names and values
  string name;
  double val;
  while (read_data >> name >> val) {
    parameter.push_back(name);
    value.push_back(val);
  }

  // Close the file
  read_data.close();

  // Print the data
  for (int i = 0; i < 7; i++) {
    cout << "Parameter: " << parameter[i] << ", Value: " << value[i] << endl;
  }

  return 0;
}

