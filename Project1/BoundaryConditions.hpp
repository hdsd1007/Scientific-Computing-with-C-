#ifndef BOUNDARYCONDITIONSHEADERDEF
#define BOUNDARYCONDITIONSHEADERDEF


class BoundaryConditions
{
    friend class BvpOde;
    
    private:
        bool mLhsBcDirichlet, mRhsBcDirichlet;
        bool mLhsBcNeumann, mRhsBcNeumann;
        double mLhsValue, mRhsValue;

    public:
        BoundaryConditions();   //Sets bool value to False
        double SetLhsDirichlet(double lhsValue);
        double SetRhsDirichlet(double rhsValue);
        double SetLhsNeumann(double lhsDeriValue);
        double SetRhsNeumann(double rhsDeriValue);

};

#endif