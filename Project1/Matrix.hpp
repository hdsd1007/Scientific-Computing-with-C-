#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>


class Matrix
{
    private:
        int mnum_rows, mnum_cols; // Stores number of rows and column
        double **mData;  // Pointer that stores data (first entry of row)
    public:
        Matrix(int rows, int cols); // Constructor
        //Matrix(const Matrix &m); // Copy Constructor
        ~Matrix(); // Destructor

        int GetRows() const; // Method to get number of rows
        int GetCols() const; // Method to get number of cols

        double& operator()(int i, int j); //Overloading round brackets for one-based indexing

        Matrix& operator=(const Matrix &otherVector); // Overloading assignment operator
        Matrix operator+() const; // Unary +
        //Const Keyword ensures that the vector on which the operator is applied to (original one) is not changed
        Matrix operator-() const; // Unary -
        Matrix operator+(const Matrix &m1) const;   //Binary +
        Matrix operator-(const Matrix &m1) const;   //Binary -

        //Scalar Multiplication
        Matrix operator*(double k) const;

        //Overloading the * operator for Dot Product
        Matrix operator*(const Matrix &v1) const;

        //Calculate Determinant of the Matrix
        double CalculateDet() const; 

        //Using Friend function to overload << Output stream; Length function
        friend std::ostream &operator<<(std::ostream &os, const Matrix &v1);

};

//Function Prototype
std::ostream &operator<<(std::ostream &os, const Matrix &v1);

#endif