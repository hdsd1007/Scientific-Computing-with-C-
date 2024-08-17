#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
    private:
        double *mData;  //Data stored in Vector
        int mSize;      // Size of a Vector
    public:
        Vector(int size);   // Specialized Constructor
        Vector(const Vector &otherVector);  // Copy Constructor
        ~Vector(); // Destructor
        int GetSize() const;
        double &operator[](int i); // Overloading Square Bracket [] for Zero-based Indexing
        double Read(int i) const; // Read-only Zero-based Indexing
        double &operator()(int i); // One-based Indexing 

};

#endif