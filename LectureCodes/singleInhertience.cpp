//Example of Single Inheritence     
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
class D: public B //Public Inheritence
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
    a = 3; b = 8;
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
    c = b*get_a(); // get_a() is from Class B
}

void D::display()
{
    std::cout << " a = " << get_a() << std::endl;
    std::cout << " b = " << b << std::endl; // Since int b is public the derived class can access from the Base Class
    std::cout << " c = " << c << std::endl;
}

int main(int argc, char *argv[])
{

    D d;

    d.get_ab();
    d.mul();
    d.show_a();
    d.display();

    //Access and changing public member of Base Class
    d.b = 2;
    d.mul();
    d.display();
    
    return 0;
}