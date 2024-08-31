#include <iostream>
#include "Book.cpp"

int main(int argc, char *argv[])
{
    /*
    Book my_book;

    // Example showing Default Constructor OverRidden
    std::cout << "Author : " << my_book.author << std::endl;
    std::cout << std::endl;

    //Initializing Values
    std::cout << "After Initializing the Book" << std::endl;
    my_book.title = "This is Title";
    my_book.author = "This is Author";
    my_book.publisher = "This is Publisher";
    my_book.format = "This is format";
    my_book.price = 499;
    my_book.set_value(1996);

    std::cout << "Author : " << my_book.author << std::endl;
    std::cout << "Title : " << my_book.title << std::endl;
    std::cout << "Publisher : " << my_book.publisher << std::endl;
    std::cout << "Format : " << my_book.format << std::endl;
    std::cout << "Year : " << my_book.get_value() << std::endl;
    std::cout << std::endl;


    //Example Showing Copying Constructor
    Book my_book_copy(my_book);
    std::cout << "Title of the copy : " << my_book_copy.title << std::endl;
    std::cout << std::endl;


    // Example showing Parameterized Constructor
    Book my_book2("Scientific Computing in CPP");
    std::cout << "My Book 2 title : " << my_book2.title << std::endl;
    */

    //EBOOK 
    Ebook myEbook;
    myEbook.title = "Guide to SCC";
    std::cout << "Title : " << myEbook.title << std::endl;
    myEbook.author = "JPT, JW";
    std::cout << "Author : " << myEbook.author << std::endl;
    std::cout << "Format : " << myEbook.format << std::endl;

    myEbook.hiddenURL = "https://ebook.example.com/example-com";
    std::cout << "URL : " << myEbook.hiddenURL << std::endl;

    return 0;

}