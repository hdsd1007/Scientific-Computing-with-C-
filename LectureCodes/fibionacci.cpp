//This code is to find the nth term of the Fibionacci Series
#include <iostream>
#include <cassert>

// Funtion Prototype
int series(int x);


//Main Function
int main(int argc, char* argv[])
{
    int n;

    //Asking user for number input
    std::cout << "Enter the number of Fibanacci Number to find: " << std::endl;
    std::cin >> n;

    //Calculate and Display the Fibonacci Series
    int result = series(n);

    std::cout << "The fibonacci number at the " << n << "th position is: " << result << std::endl;
    

    return 0;
}

//Funtion For making the fibionnaci series
int series(int x)
{
    if (x == 0){
        return 0; // First Base case for Fibonacci series
    }
    else if(x == 1){
        return 1; // Second Base Case for Fibonacci Series
    }
    else{
        return series(x - 1) + series(x - 2); //Fibonacci Series
    }
}