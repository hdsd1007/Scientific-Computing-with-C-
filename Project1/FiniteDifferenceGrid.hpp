#ifndef FINITEDIFFERENCEGRIDHEADERDEF
#define FINITEDIFFERENCEGRIDHEADERDEF

#include <vector>
#include "Node.hpp"

class FiniteDifferenceGrid
{

    friend class BvpOde;
    
    private:
        std::vector<Node> mNodes;

    public:
        FiniteDifferenceGrid(int numNodes, double xMin, double xMax);
};

#endif