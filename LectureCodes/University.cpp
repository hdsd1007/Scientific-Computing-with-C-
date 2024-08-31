#include "University.hpp"
#include <iostream>

//BASE CLASS CONSTRUCTORS AND FUNCTIONS
University::University()
{
    libFines = 0;
    Tuition = 0;
}


void University::setFine(double fine)
{
   libFines = fine;
}

double University::getFine() 
{
    return libFines;
}

double University::MoneyOwed()
{
    return (libFines + Tuition);
}

//GRADUATE CLASS

double Graduate::MoneyOwed()
{
    return (getFine() + Tuition*0); //Derived Class cannot access LinFine becoz they are private
}

//PhD Class

double Phd::MoneyOwed()
{
    return (getFine()*0 + Tuition*0) ;
}