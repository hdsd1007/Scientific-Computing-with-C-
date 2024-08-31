//STL ARRAYS
#include <iostream>

//Header file for ARRAY STL 
#include <array>

#include <cassert>
#include <vector>
#include <set>

int main(int argc, char* argv[])
{
    //Old School Array 
    int odd[4] = {1,3,5,7};

    //STL Array Syntax
    std::array<int,4> even = {2,4,6,8};

    assert(odd[3] + 1 == even[3]);

    std::array<int,4>::const_iterator c;
    for(c=even.begin();c!=even.end();c++)
    {
        std::cout << *c << std::endl;
    }


    //STL Array can be directly passed as a first reference
    std::array<int,4> num_array = {1,3,3,4};

    std::vector<int> num_vector(num_array.begin(),num_array.end());
    std::set<int> num_set(num_array.begin(),num_array.end());

    //DISPLAYING VECTOR USING THE ARRAY AS A FIRST ARG/REF
    std::cout <<"Displaying Array with the help of Vector " << std::endl;
    std::vector<int>::const_iterator d;

    for(d=num_vector.begin();d!=num_vector.end();d++)
    {
        std::cout << *d << std::endl;
    }



    return 0;
}