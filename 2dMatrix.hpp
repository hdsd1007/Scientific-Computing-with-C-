//Assignment for Simple 2D Matrix Class
#ifndef MATRIX_2D
#define MATRIX_2D

#include <iostream>
typedef double matNum;

class Matrix2d
{   
    private:
        matNum m[2][2];
    
    public:
        Matrix2d();
        Matrix2d(matNum x1, matNum x2, matNum y1, matNum y2);
        matNum CalculateDeterminant();
        Matrix2d CalculateInverse();
        Matrix2d& operator=(const Matrix2d &z); 
        Matrix2d operator-() const;
        Matrix2d operator+(const Matrix2d &z) const;
        Matrix2d operator-(const Matrix2d &z) const;
        Matrix2d MatrixMultiplier(matNum n); 
        friend std::ostream& operator<<(std::ostream& output, const Matrix2d &z);

};

#endif