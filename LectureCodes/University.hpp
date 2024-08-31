//Assignment Module 7
#ifndef  UNIVERSITYDEF
#define UNIVERSITYDEF
#include <string>

//BASE CLASS
class University
{   
    private:
        double libFines;
    public:
        std::string studentName;
        double Tuition;  
        //Member Functions
        University();
        void setFine(double fine); //Function to set the Fine
        double getFine(); //Function to get the Fine
        virtual double MoneyOwed(); //Polymorphism

};

//Deriving Class for Graduate Students from Base Class
class Graduate : public University
{
    public:
        std::string studentType; // Part Time or Full Time
        double MoneyOwed();
};

//Deriving Class for Phd students from Graduate Class
class Phd : public Graduate
{
    public:
        double MoneyOwed();
};

#endif
