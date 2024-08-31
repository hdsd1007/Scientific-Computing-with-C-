/*For Loop application using C++. The following example is for dot product*/

#include<iostream>

int main(int argc, char *argv[])
{
    //Variable in 3D
    int n = 3;

    //Two Vectors of Length n
    double v1 [n], v2 [n], v1_dot_v2;

    // Assign Vector Values to V1 and V2
    v1[0] = 2.5, v1[1] = 2.2, v1[2] = 4.5;
    v2[0] = -1.2, v2[1] = 1.4, v2[2] = 2;

    //Calculating dot product
    // v1_dot_v2 = v1[0]*v2[0] + v1[1]*v2[1] + v1[2]*v2[2];

    //Using FOR loop for dot product
    for(int i = 0; i < n; i++)
    {
        v1_dot_v2 = v1_dot_v2 + v1[i]*v2[i];
    }

    //Printing the dot product 
    std::cout <<"The dot product is " << v1_dot_v2 << std::endl;



    return 0;
}