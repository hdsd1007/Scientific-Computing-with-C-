#include <cassert>
#include "BoundaryConditions.hpp"

BoundaryConditions::BoundaryConditions()
{
    mLhsBcDirichlet = false;
    mRhsBcDirichlet = false;
    mLhsBcNeumann = false;
    mRhsBcNeumann = false;
}

void BoundaryConditions::SetLhsDirichlet(double lhsValue)
{
    assert(!mLhsBcNeumann);
    mLhsBcDirichlet = true;
    mLhsValue = lhsValue;
}

void BoundaryConditions::SetRhsDirichlet(double rhsValue)
{
    assert(!mRhsBcNeumann);
    mRhsBcDirichlet = true;
    mRhsValue = rhsValue;
}

void BoundaryConditions::SetLhsNeumann(double lhsDeriValue)
{
    assert(!mLhsBcDirichlet);
    mLhsBcNeumann = true;
    mLhsValue = lhsDeriValue;
}

void BoundaryConditions::SetRhsNeumann(double rhsDeriValue)
{
    assert(!mRhsBcDirichlet);
    mRhsBcNeumann = true;
    mRhsValue = rhsDeriValue;
}