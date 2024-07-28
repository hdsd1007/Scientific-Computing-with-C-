//EXAMPLE For STL Vectors
#include <iostream>

//Including headers to use STL Vectors
#include <vector>
#include <algorithm>

//Main Function
int main(int argc, char *argv[])
{
    //Creating a Vector named universities of data type string
    std::vector<std::string> university;

    university.reserve(6); //Reserves 6 Elements

    // Adding entries using PUSH_BACK Function
    university.push_back("MIT");
    university.push_back("Stanford");
    university.push_back("CalTech");
    university.push_back("SDSU");

    //Printing out the size of the vector using SIZE function
    std::cout << "Length of the Vector is " << university.size() << std::endl;

    //Printing the Entries of the Vectors using FOR LOOP
    std::cout << "Entries of the Vectors are " << std::endl;

    for(int i = 0; i < university.size(); i++)
    {
        std::cout << university[i] << std::endl;
    }

    //Printing using CONST_ITERATOR 
    std::cout << "Entries of the Vectors using CONST_ITERATOR are " << std::endl;   

    std::vector<std::string>::const_iterator c;

    for(c=university.begin(); c!=university.end(); c++)
    {
        std::cout << *c << std::endl;
    }

    //Adding Entry to the start of the vector using INSERT Function
    university.insert(university.begin(),"Princeton");
    university.insert(university.begin() + 1, "Cornell");

    //Printing using CONST_ITERATOR 
    std::cout << "Entries of the Vectors using CONST_ITERATOR are " << std::endl;   

    std::vector<std::string>::const_iterator d;

    for(d=university.begin(); d!=university.end(); d++)
    {
        std::cout << *d << std::endl;
    }

    

    // Removing entries from vectors using ERASE function
    university.erase(university.begin() + 4, university.end());

    std::cout << "Entries of the Vectors using CONST_ITERATOR are " << std::endl;   

    std::vector<std::string>::const_iterator e;

    for(e=university.begin(); e!=university.end(); e++)
    {
        std::cout << *e << std::endl;
    }

    return 0;
}