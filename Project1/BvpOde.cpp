#include "BvpOde.hpp"
#include <cassert>
#include <iostream>
#include <fstream>

//Public Constructor
BvpOde::BvpOde(SecondOrderOde* pOde, BoundaryConditions* pBcs, int numNodes)
{
    mpOde = pOde;
    mpBconds = pBcs;
    mNumNodes = numNodes;

    mpGrid = new FiniteDifferenceGrid(mNumNodes, pOde->mXmin, pOde->mXmax);
    
    mpSolVec = new Vector(mNumNodes);
    mpRhsVec = new Vector(mNumNodes);
    mpLhsMat = new Matrix(mNumNodes, mNumNodes);

    mFileName = "ode_output.dat";
    mpLinearSystem = NULL;

}

BvpOde::~BvpOde()
{
   // Deletes memory allocated in constructor
   delete mpSolVec;
   delete mpRhsVec;
   delete mpLhsMat;
   delete mpGrid;
   // Only delete if Solve has been called
   if (mpLinearSystem)
   {
      delete mpLinearSystem;
   }
}


void BvpOde::Solve()
{
    PopulateMatrix();
    PopulateVector();
    ApplyBoundaryConditions();

    // LinearSystem(const Matrix& A, const Vector& b); Au = b
    mpLinearSystem = new LinearSystem(*mpLhsMat,*mpRhsVec);
    *mpSolVec = mpLinearSystem->Solve();

    WriteSolutionFile();

}

void BvpOde::PopulateMatrix()
{
     for (int i=1; i<mNumNodes-1; i++)
   {
      // xm, x and xp are  x(i-1), x(i) and x(i+1) 
      double xm = mpGrid->mNodes[i-1].coordinates;
      double x = mpGrid->mNodes[i].coordinates;
      double xp = mpGrid->mNodes[i+1].coordinates;
      double alpha = 2.0/(xp-xm)/(x-xm);
      double beta = -2.0/(xp-x)/(x-xm);
      double gamma = 2.0/(xp-xm)/(xp-x);
      (*mpLhsMat)(i+1,i) = (mpOde->mCoeffOfUxx)*alpha - 
                      (mpOde->mCoeffOfUx)/(xp-xm);
      (*mpLhsMat)(i+1,i+1) = (mpOde->mCoeffOfUxx)*beta + 
                        mpOde->mCoeffOfU;
      (*mpLhsMat)(i+1,i+2) = (mpOde->mCoeffOfUxx)*gamma + 
                        (mpOde->mCoeffOfUx)/(xp-xm);
   }
}

void BvpOde::PopulateVector()
{
   for (int i=1; i<mNumNodes-1; i++)
   {
      double x = mpGrid->mNodes[i].coordinates;
      (*mpRhsVec)(i+1) = mpOde->mFuncRHS(x);
   }
}


void BvpOde::ApplyBoundaryConditions()
{
   bool left_bc_applied = false;
   bool right_bc_applied = false;

   if (mpBconds->mLhsBcDirichlet)
   {
      (*mpLhsMat)(1,1) = 1.0;
      (*mpRhsVec)(1) = mpBconds->mLhsValue;
      left_bc_applied = true;
   }

   if (mpBconds->mRhsBcDirichlet)
   {
      (*mpLhsMat)(mNumNodes,mNumNodes) = 1.0;
      (*mpRhsVec)(mNumNodes) = mpBconds->mRhsValue;
      right_bc_applied = true;
   }

   if (mpBconds->mLhsBcNeumann)
   {
      assert(left_bc_applied == false);
      double h = mpGrid->mNodes[1].coordinates - 
                 mpGrid->mNodes[0].coordinates;
      (*mpLhsMat)(1,1) = -1.0/h;
      (*mpLhsMat)(1,2) = 1.0/h;
      (*mpRhsVec)(1) = mpBconds->mLhsValue;
      left_bc_applied = true;
   }

   if (mpBconds->mRhsBcNeumann)
   {
      assert(right_bc_applied == false);
      double h = mpGrid->mNodes[mNumNodes-1].coordinates - 
                 mpGrid->mNodes[mNumNodes-2].coordinates;
      (*mpLhsMat)(mNumNodes,mNumNodes-1) = -1.0/h;
      (*mpLhsMat)(mNumNodes,mNumNodes) = 1.0/h;
      (*mpRhsVec)(mNumNodes) = mpBconds->mRhsValue;
      right_bc_applied = true;
   }

   // Check that boundary conditions have been applied
   // on both boundaries
   assert(left_bc_applied);
   assert(right_bc_applied);
}

void BvpOde::WriteSolutionFile()
{
   std::ofstream output_file(mFileName.c_str());
   assert(output_file.is_open());
   for (int i=0; i<mNumNodes; i++)
   {
      double x = mpGrid->mNodes[i].coordinates;
      output_file << x << "  " << (*mpSolVec)(i+1) << "\n";
   }
   output_file.flush();
   output_file.close();
   std::cout<<"Solution written to "<<mFileName<<"\n";
}