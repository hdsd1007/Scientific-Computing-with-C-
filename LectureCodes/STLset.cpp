//Example for STL Sets

#include <iostream>

// New header files to include SET
#include <set>
#include "point2d.hpp"

int main(int argc, char *argv[])
{
    //Syntax for SET
    std::set<Point2d> points;
    Point2d origin(0,0);

    //Using INSERT Function from SET Header file
    points.insert(origin);
    points.insert(Point2d(-1,3));
    points.insert(Point2d(2,5));

    //Using SIZE function to display size/points in the set
    std::cout <<"Number of points in set points: " << points.size() << std::endl;

    std::set<Point2d>::const_iterator c;

    for(c=points.begin(); c!=points.end(); c++)
    {
        std::cout << (*c).x << " " << (*c).y << std::endl;
    }

    return 0;
}