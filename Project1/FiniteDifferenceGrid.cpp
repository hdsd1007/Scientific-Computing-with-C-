#include "FiniteDifferenceGrid.hpp"
#include "Node.hpp"
#include <cassert>

FiniteDifferenceGrid::FiniteDifferenceGrid(int numNodes, double xMin, double xMax)
{
    double stepsise = (xMax - xMin)/((double)(numNodes - 1));
    for(int i = 0; i < numNodes; i++)
    {
        Node node;
        node.coordinates = xMin + i*stepsise;
        mNodes.push_back(node);
    }
    assert(mNodes.size() == numNodes);

}