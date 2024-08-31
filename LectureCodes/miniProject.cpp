// Mini Project 1

#include <iostream>
#include <cmath>
#include <cassert>

int main(int argc, char *argv[])
{   
    
    // Problem 1
    
    int sum = 0;
    int num;

    std::cout << "Enter positive integers to sum. Enter -1 to finish, -2 to reset sum:\n";

    while (true) 
    {
        std::cin >> num;

        if (num == -1) 
        {
            break;  // Exit loop when -1 is entered

        } 
        else if (num == -2) 
        {
            sum = 0;  // Reset sum when -2 is entered
            std::cout << "Sum reset. Enter positive integers to sum. Enter -1 to finish, -2 to reset sum:\n";
        } 
        else if (num > 0) 
        {
            sum += num;

            if (sum > 100) 
            {
                std::cout << "Sum exceeds 100. Program terminated.\n";
                return 0;  // Exit program when sum exceeds 100
            }

        } 
        else 
        {
            std::cout << "Invalid input. Please enter a positive integer.\n";
        }
    }

    std::cout << "Sum of entered integers: " << sum << "\n";
    

   //Problem 2
   
    int n=2;
    int A[n][n] = {{4, 10},{1, 1}}; 

    std::cout << "The Matrix A is " << std::endl;

        for (int i = 0; i < 2; i++) 
        { 
            for (int j = 0; j < 2; j++) 
            { 
                std::cout << A[i][j] << " "; 
            } 

            std::cout << std::endl; 
        }

    double det = ((A[0][0]*A[1][1]) - (A[0][1]*A[1][0])), invDet = 1.0/det, inv_A[n][n];
    
    assert(det != 0.0);

    std::cout << "The Determinant is " << det << std::endl;

    // Swapping Position at index [0][0], [1][1] by [1][1], [0][0] of matrix A
    inv_A[0][0] = A[1][1]*invDet;
    inv_A[1][1] = A[0][0]*invDet;

    // The other off diagonal element switch their signs
    inv_A[0][1] = -1*A[0][1]*invDet;
    inv_A[1][0] = -1*A[1][0]*invDet;

    std::cout << "Inverse Matrix of A:\n" << inv_A[0][0] << " " << inv_A[0][1] << "\n" << inv_A[1][0] << " " << inv_A[1][1] << "\n";
    
    

    
   //Problem 4

   int u[3][1] = {{1},{2},{3}}, v[3][1] = {{6},{5},{4}}, A[3][3] = {{1,5,0},{7,1,2},{0,0,1}}, B[3][3] = {{-2,0,1},{1,0,0},{4,1,0}};
   int x[3][1] ={}, y[3][1] ={}, z[3][1] = {}, C[3][3] = {}, D[3][3] = {};

   //Subquestion A
    //Loop for Calculating Matrix 
    for (int i = 0; i < 3; i++){

        for (int j = 0; j < 1; j++){
            x[i][j] = u[i][j] - v[i][j];
        }
    }
    std::cout << "The Matrix X is : \n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 1; j++){
                std::cout << x[i][j] << "\n";
            }

    }

    //Loop for Calculating Matrix Y
        for (int i = 0; i < 3; i++){

        for (int j = 0; j < 3; j++){
            y[i][0] += A[i][j]*u[0][j];
        }
    }
    std::cout << "The Matrix Y is : \n";
        for (int i = 0; i < 3; i++) {
            
                std::cout << y[i][0] << "\n";
    }

    //Loop for Calculating Matrix Z
    for (int i = 0; i < 3; i++){

        for (int j = 0; j < 3; j++){
            z[i][0] += A[i][j]*u[0][j];
        }
        z[i][0] = z[i][0] - v[i][0];
    }
    std::cout << "The Matrix Z is : \n";
        for (int i = 0; i < 3; i++) {
            
                std::cout << z[i][0] << "\n";
    }

    //Loop for Calculating Matrix C
    for (int i = 0; i < 3; i++){

        for (int j = 0; j < 3; j++){
            C[i][j] += 4*A[i][j] - 3*B[i][j]; 
        }
    }
    std::cout << "The Matrix C is : \n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++){
                std::cout << C[i][j] << " ";
            }   
        std::cout << std::endl;         
    }

    //Loop for Calculating Matrix D
    for (int i = 0; i < 3; i++){

        for (int j = 0; j < 3; j++){
            D[i][j] += A[i][j]*B[i][j]; 
        }
    }
    std::cout << "The Matrix D is : \n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++){
                std::cout << D[i][j] << " ";
            }   
        std::cout << std::endl;         
    }

    
    return 0;
}