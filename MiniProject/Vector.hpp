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
        // Overloading Operators for Vector Operations
        Vector& operator=(const Vector &otherVector);
        Vector operator+() const; // Unary +
        //Const Keyword ensures that the vector on which the operator is applied to (original one) is not changed
        Vector operator-() const; // Unary -
        Vector operator+(const Vector &v1) const;   //Binary +
        Vector operator-(const Vector &v1) const;   //Binary -



};

#endif