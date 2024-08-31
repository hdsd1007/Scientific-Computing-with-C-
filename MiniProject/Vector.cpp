#include "Vector.hpp"
#include <cassert>
#include <cmath>

// Constructor for Vector of Given Size
// Allocates Memory, and Initialises the Entries to Zero
Vector::Vector(int size)
{
    assert(size > 0);
    mSize = size;
    mData = new double [mSize];
    for(int i = 0; i < mSize; i++)
        mData[i] = 0.0;

}

// Overridden Copy Constructor
// Allocated Memory for New Vector and Copies entries of the other into it
Vector::Vector(const Vector &otherVector)
{
    mSize = otherVector.GetSize();
    mData = new double[mSize];
    for(int i = 0; i < mSize; i++)
    {
        mData[i] = otherVector.mData[i];
    }
}

// Overridden Destructor(~) to Correctly Free Memory
Vector::~Vector()
{
    delete[] mData;
}

// Method to get the Size of the Vector
int Vector::GetSize() const
{
    return mSize;
}

//Overloading Square Operator 
// NOTE: This is Zero-Based Indexing and a check on the validity of the Index
double& Vector::operator[] (int i)
{
    assert(i > -1 && i < mSize);
    return mData[i];
}

// Read-only Variant of []
// NOTE: This uses Zero-Based Indexing and a check on the Validity of the Index
double Vector::Read(int i) const
{
    assert(i > -1 && i < mSize);
    return mData[i];
}

// Overload Round Operator ()
// NOTE: This uses One-based Indexing
double& Vector::operator()(int i)
{
    assert(i > 0 && i < mSize + 1);
    return mData[i-1];
}

//Overloading the Assignment Operator
Vector& Vector::operator=(const Vector &otherVector)
{
    assert(mSize == otherVector.mSize);
    //Ensure LHS == RHS (in that order)
    for(int i=0; i < mSize; i++)
    {
        mData[i] = otherVector.mData[i];
    }
    return *this;
}

//Overloading the Unary + Operator
Vector Vector::operator+() const
{
    Vector v(mSize);
    for(int i=0; i < mSize; i++)
    {
        v[i] = mData[i];
    }

    return v;
}

//Overloading the Unary - Operator
Vector Vector::operator-() const
{
    Vector v(mSize);
    for(int i=0; i < mSize; i++)
    {
        v[i] = -mData[i];
    }

    return v;
}

//Overloading Binary + operator
Vector Vector::operator+(const Vector &v1) const
{
    assert(mSize == v1.mSize);
    Vector v(mSize);
    for(int i=0; i < mSize; i++)
    {
        v[i] = mData[i] + v1.mData[i];
    }
    return v;
}

//Overloading Binary - operator
Vector Vector::operator-(const Vector &v1) const
{
    assert(mSize == v1.mSize);
    Vector v(mSize);
    for(int i=0; i < mSize; i++)
    {
        v[i] = mData[i] - v1.mData[i];
    }
    return v;
}

//Overloading for Scalar Multiplication
Vector Vector::operator*(double k) const
{
    Vector v(mSize);
    for(int i = 0; i < mSize; i++)
    {
        v[i] = k*mData[i];
    }
    return v;
}

//Overloading for Dot Product
double Vector::operator*(const Vector &v1) const
{
    assert(mSize == v1.mSize);
    double sum(0.0);
    for(int i = 0; i < mSize; i++)
    {
        sum += mData[i]*v1.mData[i];
    }

    return sum;
}

// Overloading output stream
std::ostream& operator<<(std::ostream &os, const Vector v1)
{
    for(int i = 0; i < v1.mSize; i++)
    {
        os << v1.mData[i] << " ";
    }
    std::cout << std::endl;

    return os;
}

// Method for Calculating p-Norm using Standard L2 Method
double Vector::CalculateNorm(int p) const
{
    double norm, sum(0.0);
    for(int i = 0; i < mSize; i++)
    {
        sum += pow(fabs(mData[i]), p);
    }

    norm = pow(sum, 1.0/p);
    return norm;

}

// Method for Calculating Unit Vector 
Vector Vector::UnitVector() const
{
    Vector u(this->mSize);
    for(int i = 0; i < mSize; i++)
    {
        u.mData[i] = this->mData[i] / this-> CalculateNorm();
    }
    return u;
}






//MATLAB Style length function for Vector
int length(const Vector &v)
{
    return v.mSize;
}