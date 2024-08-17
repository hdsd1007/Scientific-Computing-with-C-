Vector.o : Vector.cpp Vector.hpp
		g++ -Wall -c Vector.cpp
main.o : main.cpp Vector.hpp
		g++ -Wall -c main.cpp
Vector : main.o Vector.o
		g++ -o Vector main.o Vector.o