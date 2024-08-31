#include <iostream>
#include "Guest.hpp"
#include "SpecialGuest.hpp"

int main(int argc, char *argv[])
{
    Guest *pg1 = new Guest;
    Guest *pg2 = new SpecialGuest;

    pg1->telephoneBill = 5;
    pg2->telephoneBill = 15;

    pg1->numberOfNights = 10;
    pg2->numberOfNights = 10;

    std::cout << "Total Bill for Guest 1 = " << pg1->CalculateBill() <<std::endl;
    std::cout << "Total Bill for Guest 2 = " << pg2->CalculateBill() <<std::endl;
    
    return 0;
}