#include "LinearSystem.hpp"
#include <cmath>
#include <stdexcept>

LinearSystem::LinearSystem(const Matrix& A, const Vector& b)
{
    if (A.GetRows() != A.GetCols() || A.GetRows() != b.GetSize()) {
        throw std::invalid_argument("Matrix A must be square and compatible with vector b");
    }

    mSize = A.GetRows();
    mpA = new Matrix(A);
    mpb = new Vector(b);
}

LinearSystem::~LinearSystem()
{
    delete mpA;
    delete mpb;
}

Vector LinearSystem::Solve() const
{
    Matrix A = *mpA;  // Create a copy to avoid modifying the original
    Vector b = *mpb;

    // Gaussian elimination with partial pivoting
    for (int k = 0; k < mSize - 1; k++) {
        // Find pivot
        int maxIndex = k;
        double maxAbs = std::abs(A(k+1, k+1));
        for (int i = k + 1; i < mSize; i++) {
            if (std::abs(A(i+1, k+1)) > maxAbs) {
                maxIndex = i;
                maxAbs = std::abs(A(i+1, k+1));
            }
        }

        // Swap rows if necessary
        if (maxIndex != k) {
            for (int j = k; j < mSize; j++) {
                double temp = A(k+1, j+1);
                A(k+1, j+1) = A(maxIndex+1, j+1);
                A(maxIndex+1, j+1) = temp;
            }
            double temp = b(k+1);
            b(k+1) = b(maxIndex+1);
            b(maxIndex+1) = temp;
        }

        // Eliminate
        for (int i = k + 1; i < mSize; i++) {
            double factor = A(i+1, k+1) / A(k+1, k+1);
            for (int j = k + 1; j < mSize; j++) {
                A(i+1, j+1) -= factor * A(k+1, j+1);
            }
            b(i+1) -= factor * b(k+1);
        }
    }

    // Back substitution
    Vector x(mSize);
    for (int i = mSize - 1; i >= 0; i--) {
        double sum = 0.0;
        for (int j = i + 1; j < mSize; j++) {
            sum += A(i+1, j+1) * x(j+1);
        }
        x(i+1) = (b(i+1) - sum) / A(i+1, i+1);
    }

    return x;
}