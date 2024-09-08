#ifndef LINEARSYSTEMS_HPP
#define LINEARSYSTEMS_HPP

#include "Matrix.hpp"
#include "Vector.hpp"

class LinearSystem {
private:
    int mSize;
    Matrix* mpA;
    Vector* mpb;

    // Private copy constructor to prevent use
    LinearSystem(const LinearSystem& otherLinearSystem);

public:
    // Constructor
    LinearSystem(const Matrix& A, const Vector& b);

    // Destructor
    ~LinearSystem();

    // Solve the linear system
    Vector Solve() const;

    // Getter methods
    int GetSize() const { return mSize; }
    const Matrix& GetMatrix() const { return *mpA; }
    const Vector& GetVector() const { return *mpb; }
};

#endif // LINEARSYSTEMS_HPP