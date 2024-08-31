//Storing All Constructors and Member Functions
#include "2dMatrix.hpp"

#include <cmath>

//Over-ridden Default Constructor to set all initial values to zero
Matrix2d::Matrix2d()
{
    m[0][0] = 0.0; m[0][1] = 0.0; 
    m[1][0] = 0.0; m[1][1] = 0.0;
}


//Constructor Specifying four entries of the Matrix
Matrix2d::Matrix2d(matNum x1, matNum x2, matNum y1, matNum y2)
{
    m[0][0] = x1; m[0][1] = x2; 
    m[1][0] = y1; m[1][1] = y2;
}

//Method Function to Calculate the Determinant
matNum Matrix2d::CalculateDeterminant()
{
    return (m[0][0]*m[1][1] - m[0][1]*m[1][0]);
}

//Method Function to Calculate the Inverse of Matrix
Matrix2d Matrix2d::CalculateInverse()
{
    matNum w = CalculateDeterminant();

    if(w == 0){
        throw std::runtime_error("Matrix is not invertible");
    }
    else{
        matNum invDet = 1.0 / w;
        return Matrix2d(
        invDet * m[1][1], -invDet * m[0][1],
        -invDet * m[1][0], invDet * m[0][0]
        );
    }
}

//Assignment Operator Overloading 
Matrix2d& Matrix2d::operator=(const Matrix2d &z)
{
    m[0][0] = z.m[0][0];
    m[0][1] = z.m[0][1];
    m[1][0] = z.m[1][0];
    m[1][1] = z.m[1][1];

    return *this;
}

//Unary Subtraction Operator Overload
Matrix2d Matrix2d::operator-() const
{
    Matrix2d z;

    z.m[0][0] = -m[0][0];
    z.m[0][1] = -m[0][1];
    z.m[1][0] = -m[1][0];
    z.m[1][1] = -m[1][1];

    return z;  
}

//Binary Operator Overloading 
Matrix2d Matrix2d::operator+(const Matrix2d &z) const
{
    Matrix2d w;
    w.m[0][0] = m[0][0] + z.m[0][0];
    w.m[0][1] = m[0][1] + z.m[0][1];
    w.m[1][0] = m[1][0] + z.m[1][0];
    w.m[1][1] = m[1][1] + z.m[1][1];
    return w;
}

//Binary Subtraction Overloading 
Matrix2d Matrix2d::operator-(const Matrix2d &z) const
{
    Matrix2d w;
    w.m[0][0] = m[0][0] - z.m[0][0];
    w.m[0][1] = m[0][1] - z.m[0][1];
    w.m[1][0] = m[1][0] - z.m[1][0];
    w.m[1][1] = m[1][1] - z.m[1][1];
    return w;
}

//Method for Matrix Multiplier
Matrix2d Matrix2d::MatrixMultiplier(matNum n)
{
    return Matrix2d(
        n * m[0][0], n * m[0][1],
        n * m[1][0], n * m[1][1]
        );
}

std::ostream& operator<<(std::ostream& output, const Matrix2d &z)
{
    //Format as "x + yi" or as "x - yi" 
    output << "[" << z.m[0][0] << " " << z.m[0][1] << "] \n";
    output << "[" << z.m[1][0] << " " << z.m[1][1] << "]";
    
    return output;
}