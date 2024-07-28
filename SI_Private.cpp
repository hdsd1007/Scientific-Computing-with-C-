//Example of Single Inheritence with Private Privilege     
#include <iostream>

class B
{   
    private:
        int a; 

    public:
        int b;
        void get_ab();
        int get_a();
        void show_a();
};

//Single Inheritence
class D: private B //Private Inheritence
{
    private:
        int c;
    
    public:
        void mul();
        void display();
};

//=======================================//

void B::get_ab()
{
    std::cout << "Enter Values for a and b: " << std::endl; //Modified for Derived class to access a and b
    std::cin >> a >> b;
    //a = 3; b = 8;
}

int B::get_a()
{
    return a;
}

void B::show_a()
{
    std::cout << "a = " << a << std::endl;
}

void D::mul()
{
    get_ab();
    c = b*get_a(); // get_a() is from Class B
}

void D::display()
{
    show_a();
    //std::cout << " a = " << get_a() << std::endl;
    std::cout << " b = " << b << std::endl; // Private Member can be recalled within the Function
    std::cout << " c = " << c << std::endl;
}

int main(int argc, char *argv[])
{

    D d;

    //d.get_ab(); //Won't Work
    d.mul();
    //d.show_a(); //Won't Work
    d.display();

    //==========================//
    d.mul();
    d.display();
    
    return 0;
}