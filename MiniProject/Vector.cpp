#include "Vector.hpp"
#include <cassert>

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

// Overridden Destructor to Correctly Free Memory
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