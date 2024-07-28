# include <iostream>
# include <cmath>

int main (int argc, char *argv[])
{
    // Declaring and Initializing Variables

    int min, max;

    // Finding the Minimum and Maximum value of the int type
    // 1 Byte = 8 bits
    // sizeof function gives the output in BYTES
    // Here we have Negative - 1 in the power because on bit is assigned to denote sign
    // This wont be the case for unsigned int type
    min = pow(2,sizeof(short int)*8 - 1)*(-1);
    max = pow(2,sizeof(short int)*8 - 1) - 1;

    std::cout << "Range of short int type : " << std::endl;
    std::cout << min << " to " << max << std::endl;

    min = pow(2,sizeof(long int)*8 - 1)*(-1);
    max = pow(2,sizeof(long int)*8 - 1) - 1;

    std::cout << "Range of long int type : " << std::endl;
    std::cout << min << " to " << max << std::endl;

    /*
    // unsigned int type
    // Note we need to declare new variable for this

    int maxima;
    double maxima_long;

    maxima = pow(2,sizeof(unsigned short int)*8) - 1;

    std::cout << "Range of unsigned short int type : " << std::endl;
    std::cout << 0 << " to " << maxima << std::endl;

    maxima_long = pow(2,sizeof(unsigned long int)*8);

    std::cout << "Range of unsigned long int type : " << std::endl;
    std::cout << 0 << " to " << maxima_long << std::endl;
    */

   //Determining the Minimum and Maximum of float type

   double low, high;

    // double type
    low = pow(2,sizeof(double)*8 - 1)*(-1);
    high = pow(2,sizeof(double)*8 - 1) - 1;

    std::cout << "Range of double type : " << std::endl;
    std::cout << low << " to " << high << std::endl;

    // float type
    low = pow(2,sizeof(float)*8 - 1)*(-1);
    high = pow(2,sizeof(float)*8 - 1) - 1;

    std::cout << "Range of float type : " << std::endl;
    std::cout << low << " to " << high << std::endl;

    /*
    // Finding Machine Precision of using Standard library of the current system
    std::cout << "The Machine Precision for float type is : " << std::numeric_limits<float>::epsilon() << std::endl;
    std::cout << "The Machine Precision for double type is : " << std::numeric_limits<double>::epsilon() << std::endl;
    std::cout << "The Machine Precision for long double type is : " << std::numeric_limits<long double>::epsilon() << std::endl;
    */


    // Division of integers

    int a = 22, b = 7;
    double c;

    c = ((double)(a))/((double)(b));

    std::cout << "The division of a by b is = " << c << std::endl;

}