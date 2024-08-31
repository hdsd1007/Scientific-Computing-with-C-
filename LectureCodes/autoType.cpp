//Example for Auto Type keyword

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
    //Declaring and Initializing the variable at the Same time while using Auto keyword
    auto x = 4;
    auto y =3.144;
    auto ptr_x = &x;
    auto ptr_y = &y;

    //Printing out the values for each auto variable
    std::cout << " x = " << x << std::endl;
    std::cout << " y = " << y << std::endl;
    std::cout << " Location of ptr_x = " << ptr_x << " Value of ptr_x " << *ptr_x << std::endl;
    std::cout << " Location of ptr_y = " << ptr_y << " Value of ptr_y " << *ptr_y << std::endl;

    //Using function typeid(ARG).name() for seeing the type of variable
    std::cout << " " << typeid(x).name() << std::endl;
    std::cout << " " << typeid(y).name() << std::endl;
    std::cout << " " << typeid(ptr_x).name() << std::endl;
    std::cout << " " << typeid(ptr_y).name() << std::endl;

    //Application of Auto Type as iterators for Vectors/Sets (Container)
    std::vector<std::string> myVec;
    
    //Using PushBack function to add Strings to the vector
    myVec.push_back("Scientific");
    myVec.push_back("Computing");
    myVec.push_back("with");
    myVec.push_back("C++");

    //Using standard iterators from vectors/sets
    std::vector<std::string>::const_iterator c;
    std::cout << "Standard Iterator Example" << std::endl;

    for(c=myVec.begin();c!=myVec.end();c++)
    {
        std::cout << *c << " ";
    }
    std::cout << std::endl;

    //Using Auto Keyword iterators from vectors/sets
    std::cout << "Auto Keyword Iterator Example" << std::endl;

    for(auto it=myVec.begin(); it!=myVec.end(); it++)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    return 0;
}