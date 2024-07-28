#include "friendFunc.hpp"

// Constructor to Set the Private Member (Initialization)
ExampleClass::ExampleClass(double var1, double var2)
{

    mvar1 = var1;
    mvar2 = var2;

}

// get_minimum is a Member FUNCTION (THE CODE BELOW IS A FUNCTION, SO REMEMBER TO SPECIFY RETURN TYPE) 
double ExampleClass::get_minimum() const{
    if (mvar1 < mvar2){
        return mvar1;
    }
    else{
        return mvar2;
    }
}

// get_maximum is a FRIEND Funtion, It has to be initialized using regular method
double get_maximum(const ExampleClass &example)
{
    if (example.mvar1 < example.mvar2){
        return example.mvar2;
    }
    else{
        return example.mvar1;
    }
}