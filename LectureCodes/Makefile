ComplexNumber.o : ComplexNumber.cpp ComplexNumber.hpp
    g++ -Wall -c ComplexNumber.cpp

main.o : main.cpp ComplexNumber.hpp
    g++ -Wall -c main.cpp

ComplexNumber : main.o ComplexNumber.o
    g++ -o ComplexNumber main.o ComplexNumber.o