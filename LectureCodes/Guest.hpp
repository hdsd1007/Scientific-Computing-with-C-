#ifndef GUESTDEF
#define GUESTDEF

#include <string>

class Guest
{
    public:
        std::string name, roomType, arrivalDate;
        int numberOfNights;
        double telephoneBill;
        //Employing Polymorphism Virtual Method
        virtual double CalculateBill();
};

double Guest::CalculateBill()
{
    return (telephoneBill + numberOfNights*50);

}



#endif