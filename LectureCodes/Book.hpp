//Header file for Book Class
#ifndef BOOKHEADERDEF
#define BOOKHEADERDEF

#include <string>

class Book
{   
    private:
        int my_year;

    public:
        Book(); // Default Constructor

        Book(const Book &b); //Copy Constructor with Reference to Book and copy b

        Book(std::string book_title); //Parameterized Constructor initializing the book title 

        std::string author, title, publisher, format;
        int price;
        void set_value(int year);
        int get_value() const;

};

#endif