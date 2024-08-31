#ifndef EBOOKHEADERDEF
#define EBOOKHEADERDEF

#include <string>
#include "Book.hpp"

//PUBLIC InheritanceS
class Ebook: public Book
{
    public:
        Ebook();
        std::string hiddenURL;
};


#endif