// Template Specialization for CHAR Data type
#include <iostream>

template <class T>
class myIncrement
{
    private:
        T value;

    public:
        myIncrement(T arg) : value(arg) {}
        T toIncrement() {return value += 1; }
};

//Class Template Specialization
template<>
class myIncrement<char>
{
    private:
        char value;

    public:
        myIncrement(char arg) {value = arg;}
        char uppercase()
        {
            if((value >= 'a') or (value <= 'z'))
                value += 'A' - 'a';
            
            return value;
        }
};

//Main Function

int main(int argc, char *argv[])
{

    myIncrement<int> myint(7);
    myIncrement<char> mychar('k');

    std::cout << "Incremented Value = " << myint.toIncrement() << std::endl;
    std::cout << "Uppercase Value = " << mychar.uppercase() << std::endl;

    return 0;
}