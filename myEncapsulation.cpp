//Code for Understanding Encapsulation
#include <iostream>

class Encapsulation
{
    private:
        //Data Members hidden from user
        double x;

    public:
        //Data Members accessible to users
        double y;

        //Member functions acting on Data Members
        void set_value(double value)
        {
            x = value;
        }

        //Member function to return/retreive the data

        double get_value() const
        {
            return x;
        }
};


int main(int argc, char* argv[])
{


    Encapsulation my_object;

    my_object.set_value(3.14);

    std::cout << " x = " << my_object.get_value() << std::endl;



    return 0;
}