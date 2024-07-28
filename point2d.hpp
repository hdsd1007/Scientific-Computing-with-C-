// Point 2D Header File to demonstrate the example of SET

class Point2d
{
    public:
        int x,y;
        Point2d(int a, int b)
        {
            x = a;
            y = b;
        }

        //Overloading the < Operator
        bool operator<(const Point2d &other) const
        {
            if(x < other.x)
                return true;
            else if(x > other.x)
                return false;
            else if(y < other.y)
            {
                //x = other.x
                return true;
            }
            else{
                // x = other.x
                // y >= other.y
                return false;
            }
        }
};