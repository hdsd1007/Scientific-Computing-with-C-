#ifndef BVPODEHEADERDEF
#define BVPODEHEADERDEF

#include "SecondOrderODE.hpp"
#include "BoundaryConditions.hpp"
#include "FiniteDifferenceGrid.hpp"
#include "Vector.hpp"
#include "Matrix.hpp"
#include "LinearSystem.hpp"

class BvpOde
{

    private:
        //Copy Constructor
        BvpOde(const BvpOde& otherBvpOde){}

        //Pointer to an instance of ODE
        SecondOrderOde* mpOde;

        //Pointer to an instance of Boundary Conditions
        BoundaryConditions* mpBconds;

        //Number of Nodes in the grid and pointer to the grid
        int mNumNodes;
        FiniteDifferenceGrid* mpGrid;

        //Vector for the Solutions of the Unknowns
        Vector* mpSolVec;

        //Right-hand Side Vector
        Vector* mpRhsVec;

        // Matrix for Linear System
        Matrix* mpLhsMat;

        //Linear System that Arises
        LinearSystem* mpLinearSystem;

        //Methods for Setting Up Linear System and Solving it
        void PopulateMatrix();
        void PopulateVector();
        void ApplyBoundaryConditions();

        //Allow user to Specify the Output File or Use a default name
        std::string mFileName;



    
    public:
        //Constructor
        BvpOde(SecondOrderOde* pOde, BoundaryConditions* pBcs, int numNodes);

        //Overloaded Destructor as Memory is allocated dynamically
        ~BvpOde();

        void SetFileName(const std::string& name)
        {
            mFileName = name;
        }

        void Solve();
        void WriteSolutionFile();





};

#endif