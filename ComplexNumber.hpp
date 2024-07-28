//  MINI PROJECT FOR COMPLEX CLASS AND OPERATOR OVERLOADING 
#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include<iostream>

typedef double myReal;

class ComplexNumber
{
    private:
        double mreal;
        double mimag;
    
    public:
        ComplexNumber();
        ComplexNumber(double x, double y);
        double CalculateModulus() const;
        double CalculateArgument() const;
        ComplexNumber CalculatePower(double n) const;
        ComplexNumber& operator=(const ComplexNumber &z);
        ComplexNumber operator-() const;
        ComplexNumber operator+(const ComplexNumber &z) const;
        ComplexNumber operator-(const ComplexNumber &z) const;
        friend std::ostream& operator<<(std::ostream& output, const ComplexNumber &z);
        //Assignment 
        myReal GetRealPart() const;
        myReal GetImaginaryPart() const;
        friend myReal RealPart(const ComplexNumber& z);
        friend myReal ImaginaryPart(const ComplexNumber& z); 
        ComplexNumber CalculateConjugate();
        void SetToConjugate(const ComplexNumber& z);

};


#endif
