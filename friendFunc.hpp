#ifndef EXAMPLECLASSDEF
#define EXAMPLECLASSDEF

class ExampleClass
{
    private:
        double mvar1, mvar2;
    
    public:
        ExampleClass(double var1, double var2); // Constructor
        double get_minimum() const;
        friend double get_maximum(const ExampleClass &example); // Friend Declaration

};

#endif