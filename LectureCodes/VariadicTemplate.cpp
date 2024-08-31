//Example for Variadic Template for multiple arguments
#include <iostream>
#include <string>

//Base Template Function for Summation
template<typename T>
T summation(T val)
{
    return val;
}


//Variadic Function based on the Base Function
template<typename T, typename ... Args>
T summation(T first, Args ... args)
{
    return first + summation(args...);
}

//Main Function

int main(int argc, char *argv[])
{
    int sum = summation(2,43,1,12,123,44);
    std::cout <<"Summation of the integers: " << sum << std::endl;

    //Example Demonstrating the use of Character Concatenation using the Variadic Template
    std::string s1 = "H",s2 = "i",s3 = "m",s4 = "a",s5 = "n",s6 = "s",s7 = "H",s8 = "u";
    std::string concat = summation(s1,s2,s3,s4,s5,s6,s7,s8);

    std::cout << "Concatinated Strings: " << concat << std::endl;


    return 0;
}