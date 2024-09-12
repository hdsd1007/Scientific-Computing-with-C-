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
        void SetLhsDirichlet(double lhsValue);
        void SetRhsDirichlet(double rhsValue);
        void SetLhsNeumann(double lhsDeriValue);
        void SetRhsNeumann(double rhsDeriValue);

};

#endif