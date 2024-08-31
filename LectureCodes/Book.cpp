#include "Book.hpp"
#include "Ebook.hpp"
#include <iostream>

// Default Constructor OverRidden
Book::Book()
{
    std::cout << "Book Instance Created with Default Constructor" << std::endl;
    author = "not yet assigned";
    title = "not yet assigned";
    publisher = "not yet assigned";
    format = "not yet assigned";

}

//Copy Constructor OverRidden
Book::Book(const Book &b)
{   
    std::cout << "Invoking Copy Constructor" << std::endl;
    author = b.author;
    title = b.title;
    publisher = b.publisher;
    format = b.format;
    price = b.price;
    my_year = b.get_value();

}

//Parameterized Constructor OverRidden
Book::Book(std::string book_title)
{   
    std::cout << "Invoking Parameterized Constructor" << std::endl;
    title = book_title;
}

void Book::set_value(int year)
{
    my_year = year;
}

int Book::get_value() const
{
    return my_year;
}

//Overriding defalult Constructer for Derived Class (EBOOK)
Ebook::Ebook() :Book()
{
    format = "Electronic";
}