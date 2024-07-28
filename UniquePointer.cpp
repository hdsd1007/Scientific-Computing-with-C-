//Code Demonstrating the use of Unique Pointer in C++

#include <iostream>
//New Header file for Unique Pointers (C++11 or above)
#include <memory>

#include <cassert>

int main(int argc, char* argv[])
{
    //Creating Unique Pointer 
    std::unique_ptr<int> p_x(new int);

    //Using Pointer De-referencing to assign a value to pointer p_x
    *p_x = 5;

    //Printing out the Unique Address(memory location) the pointer is pointing to; using get() method
    std::cout <<"Unique Pointer p_x Memory location : " << p_x.get() << std::endl;
    std::cout <<"Value stored in the Unique Pointer p_x: " << *p_x << std::endl;


    //The following line of code will not compile as Unique Pointer prevents Pointer Aliasing
    // int *p_y = p_x;

    //Pointing Raw Pointer to unique pointer using get() function
    int *p_y = p_x.get();
    std::cout << "Raw Pointer p_y points to the memory location : " << p_y << std::endl;
    std::cout << "Accessing value using Raw Pointer p_y : " << *p_y << std::endl;

    //Transferring Ownership from one unique pointer to another (p_x -> p_y)
    std::unique_ptr<int> p_z;
    p_z = std::move(p_x);
    std::cout << "Unique Pointer p_z points to the memory location : " << p_z.get() << std::endl;
    std:: cout << "Accessing value using unique pointer p_z : " << *p_z << std::endl;

    //Since p_x is not in use because of transferring ownership it is AUTOMATICALLY DELETED by Unique Pointer
    //We can check if pointer is in USE or NOT by assert statement

    assert(p_z); //Test if p_z is in use
    assert(!p_x); //Test if p_x is NOT in use

    return 0;
}
