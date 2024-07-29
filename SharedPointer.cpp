//Code demonstratin g the use of Shared Pointer 

#include<iostream>
//Header file for Shared Pointer
#include<memory>


int main(int argc, char *argv[])
{
    //Creating Shared Pointer
    std::shared_ptr<int> p_x(new int);
    std::cout << "Shared Pointer p_x is pointing to the Memory Location: " << p_x.get() << std::endl;
    std::cout << "p_x Use Count : " << p_x.use_count() << std::endl;

    //Using Pointer De-referencing to assign a value to pointer p_x
    *p_x = 5;
    std::cout << "Value Assigned using Shared Pointer p_x : " << *p_x << std::endl;

    //Memory Aliasing is possible using Shared Pointers
    std::shared_ptr<int> p_y = p_x;
    //The count for p_x should increment to 2
    std::cout << "p_x Use Count : " << p_x.use_count() << std::endl;
    std::cout << "Shared Pointer p_y is pointing to the Memory Location: " << p_y.get() << std::endl;
    std::cout << "Value assigned to Shared Pointer p_y : " << *p_y << std::endl;

    //Reset Funtions de-allocates the memory
    p_y.reset();
    std::cout << "\n p_x use count : " << p_x.use_count() << std::endl;

    p_x.reset();
    std::cout << "\n p_x use count : " << p_x.use_count() << std::endl;


    return 0;
}