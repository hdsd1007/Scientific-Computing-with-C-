#ifndef SECONDORDERHEADER
#define SECONDORDERHEADER


class SecondOrderOde
{   
    //Make another Class a Friend to this class to access members [Boundary Value Class]
        friend class BvpOde;
        
    private:
        //Coefficients of LHS of 2nd order linear ODE
        double mCoeffOfUxx; double mCoeffOfUx; double mCoeffOfU;
        // Pointer to the Function on RHS
        double (*mFuncRHS)(double x);
        // Boundary Value Interval
        double mXmin; double mXmax;

    public:
        SecondOrderOde(double CoeffOfUxx, double CoeffOfUx, double CoeffOfU, double (*FuncRHS)(double x), double xMin, double xMax)
        {
            mCoeffOfUxx = CoeffOfUxx; mCoeffOfUx = CoeffOfUx; mCoeffOfU = CoeffOfU; mFuncRHS = FuncRHS; mXmin = xMin;
            mXmax = xMax;
        }
};



#endif