// Making use of Header File for Book Class
#include <iostream>
#include "Book.hpp" //Remember to always use the header 

int main(int argc, char* argv[])
{

    Book mybook;

    mybook.author = "Anonymous";
    mybook.title = "LOL";
    mybook.publisher = "McGraw Hill";
    mybook.format = "HardBind";

    mybook.year = 2013;
    mybook.price = 498;

    std::cout << "The book " << mybook.title << " was published in " << mybook.year << " by " << mybook.publisher << std::endl;


    return 0;
}