#include "Matrix.hpp"
#include <cassert>
#include <cmath>

// Constructor for Matrix of Given Size
// Allocates Memory, and Initialises the Entries to Zero
Matrix::Matrix(int rows, int cols)
{
    assert(cols > 0 && rows > 0);
    mnum_cols = cols; mnum_rows = rows;

    //Allocating memory for the Matrix
    mData = new double* [mnum_rows];
    for(int i = 0; i < mnum_rows; i++)
    {
        mData[i] = new double [mnum_cols];
    }
    
     //Initializes all entries to zero
    for(int i = 0; i < mnum_rows; i++)
    {
        for(int j = 0; j < mnum_cols; j++)
        {
            mData[i][j] = 0.0;
        } 
    }

    //std::cout << "Matrix created with " << mnum_rows << " rows and " << mnum_cols << " cols" << std::endl;

}


// Overloading output stream
std::ostream& operator<<(std::ostream &os, const Matrix &v1)
{
    for(int i = 0; i < v1.mnum_rows; i++)
    {
        for(int j = 0; j < v1.mnum_cols; j++)
        {
            os << v1.mData[i][j] << " ";
        }
        std::cout << std::endl;    
    }

    return os;
}


//Destructor to free memory
Matrix::~Matrix()
{
    for(int i = 0; i < mnum_rows; i++)
    {
        delete[] mData[i];
    }
    delete[] mData;
}

//Method to Get the number of rows
int Matrix::GetRows() const
{
    return mnum_rows;
}

//Method to Get the number of columns
int Matrix::GetCols() const
{
    return mnum_cols;
}

//Overloading the Round Bracket operator for one-based indexing
double& Matrix::operator()(int i, int j)
{
    assert(i > 0 && i < mnum_rows+1);
    assert(j > 0 && j < mnum_cols+1);
    return mData[i-1][j-1];
}

//Overloading the Assignment Operator
Matrix& Matrix::operator=(const Matrix &otherVector)
{
    assert(mnum_cols == otherVector.mnum_cols);
    assert(mnum_rows == otherVector.mnum_rows);
    for(int i = 0; i < mnum_rows; i++)
    {
        for(int j = 0; j < mnum_cols; j++)
        {
            mData[i][j] = otherVector.mData[i][j];
        }
    }

    return *this;
}

//Overloading the Unary Subtraction operator
Matrix Matrix::operator-() const
{
    Matrix A(mnum_rows,mnum_cols);
    for(int i = 0; i < mnum_rows; i++)
    {
        for(int j = 0; j < mnum_cols; j++)
        {
            A(i+1, j+1) = -mData[i][j];
        }
    } 

    return A;   
}

//Overloading the Binary Addition Operator
Matrix Matrix::operator+(const Matrix &m1) const
{
    assert(mnum_cols == m1.mnum_cols);
    assert(mnum_rows == m1.mnum_rows);
    Matrix m2(mnum_rows,mnum_cols);
    for(int i = 0; i < mnum_rows; i++)
    {
        for(int j = 0; j < mnum_cols; j++)
        {
            m2(i+1, j+1) = mData[i][j] + m1.mData[i][j];
        }
    } 

    return m2;
}

//Overloading the Binary Subtraction Operator
Matrix Matrix::operator-(const Matrix &m1) const
{
    assert(mnum_cols == m1.mnum_cols);
    assert(mnum_rows == m1.mnum_rows);
    Matrix m2(mnum_rows,mnum_cols);
    for(int i = 0; i < mnum_rows; i++)
    {
        for(int j = 0; j < mnum_cols; j++)
        {
            m2(i+1, j+1) = mData[i][j] - m1.mData[i][j];
        }
    } 

    return m2;
}

//Overloading the Multiplication Operator for SCALAR Product
Matrix Matrix::operator*(double k) const
{
    Matrix A(mnum_rows,mnum_cols);
    for(int i = 0; i < mnum_rows; i++)
    {
        for(int j = 0; j < mnum_cols; j++)
        {
            A(i+1, j+1) = k*mData[i][j];
        }
    }
    return A;    
}

//Overloading the Multiplication Operator for DOT Product
Matrix Matrix::operator*(const Matrix &v1) const
{
    assert(mnum_cols == v1.mnum_rows);
    Matrix result(mnum_rows, v1.mnum_cols);
    for (int i = 0; i < mnum_rows; i++)
    {
        for (int j = 0; j < v1.mnum_cols; j++)
        {
            for (int k = 0; k < mnum_cols; k++)
            {
                result.mData[i][j] += mData[i][k] * v1.mData[k][j];
            }
        }
    }
    return result;
}

//Calculating the determinant of the Matrix
double Matrix::CalculateDet() const
{
     assert(mnum_rows == mnum_cols && "Determinant is only defined for square matrices");
    
    // LU Decomposition
    Matrix L(mnum_rows, mnum_cols);
    Matrix U(mnum_rows, mnum_cols);

    for (int i = 0; i < mnum_rows; i++) {
        // Upper Triangular
        for (int k = i; k < mnum_cols; k++) {
            double sum = 0.0;
            for (int j = 0; j < i; j++) {
                sum += L(j+1, i+1) * U(i+1, k+1);
            }
            U(i+1, k+1) = mData[i][k] - sum;
        }

        // Lower Triangular
        for (int k = i; k < mnum_rows; k++) {
            if (i == k) {
                L(i+1, i+1) = 1.0; // Diagonal as 1
            } else {
                double sum = 0.0;
                for (int j = 0; j < i; j++) {
                    sum += L(k+1, j+1) * U(j+1, i+1);
                }
                L(k+1, i+1) = (mData[k][i] - sum) / U(i+1, i+1);
            }
        }
    }

    // Calculate determinant as product of diagonal elements of U
    double det = 1.0;
    for (int i = 0; i < mnum_rows; i++) {
        det *= U(i+1, i+1);
    }

    return det;
    
}