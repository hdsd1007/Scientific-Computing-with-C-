// lesson 9:: If Else Statement
// The code attempts to address all the three questions at one
// Question 1 == A; Question 2 == B; Question 3 == C;

#include <iostream>
#include <cmath>
#include <string>

int main(int argc, char *argv[])
{
    // First ask user which question they want to solve Q1, Q2, Q3

    char question; // Char variable type because input is single alphabet
    std::string password, user_password; //String Variable Type
    password = "CPP#20";

    double num1, num2;

    std::cout << "Which question do you want to solve from A, B or C ?" << std::endl;
    std::cin >> question;

    if (question == 'A')
    {
        std::cout << "This is question 1" << std::endl;
        std::cout << "Please enter your password for the CPP class ?" << std::endl;
        std::cin >> user_password;
            if (password == user_password)
            {
                //The user types the correct password
                std::cout << "You have entered the Correct Password!" << std::endl;
            }
            else
            {
                //The user types the incorrect password
                std::cout << "Unfortunately, you entered the incorrect password!!" << std::endl; 
            }
    }
    else if (question == 'B')
    {
        std::cout << "This is question 2" << std::endl;
        std::cout << "Enter two numbers for comparison" << std::endl;
        std::cin >> num1 >> num2;
        if (num1 > num2)
        {
            // Num1 is greater than Num2
            std::cout << "The number " << num1 << " is greater than " << num2 << std::endl;
        }
        else if (num1 < num2)
        {   
            //Num2 is greater than Num1
           std::cout << "The number " << num2 << " is greater than " << num1 << std::endl; 
        }
        else
        {   
            //Num1 equals Num2
            std::cout << "Both the numbers are equal!!" << std::endl;
        }

    }
    else if (question == 'C')
    {
        std::cout << "This is question 3" << std::endl;
        std::cout << "This question will show whether the number you entered is positive or negative" << std::endl;
        std::cout << "Enter a number of your choice: " << std::endl;
        std::cin >> num1;
        if (num1 >= 0)
        {
            //The number is positive
            std::cout << "The number you entered " << num1 << " is Positive!!" << std::endl;
            
        }
        else 
        {
           //The number is positive
            std::cout << "The number you entered " << num1 << " is Negative!!" << std::endl; 
        }

    }
    else
    {
        //User selects neither A,B or C
        std::cout << "Invalid Input!!" << std::endl;

    }





















    return 0;
}