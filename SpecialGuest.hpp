#ifndef SPECIALGUESTDEF
#define SPECIALGUESTDEF

#include "Guest.hpp"

class SpecialGuest : public Guest
{
    public:
        double CalculateBill();
};

double SpecialGuest::CalculateBill()
{
    return (45 + (numberOfNights-1)*40 + telephoneBill);
}


#endif