#include <cmath>
#include <string>
#include "BvpOde.hpp"

// Test Problem 1 RHS
double model_prob_1_rhs(double x){return 1.0;}

//Test Problem 2 RHS
double model_prob_2_rhs(double x){return 34.0*sin(x);}

int main(int argc, char* argv[])
{
    //Test Problem 1
    SecondOrderOde P1(-1,0,0,model_prob_1_rhs,0,1);
    BoundaryConditions bcP1;
    bcP1.SetLhsDirichlet(0);
    bcP1.SetRhsDirichlet(0);

    BvpOde ode_P1(&P1, &bcP1, 101);
    ode_P1.SetFileName("Results_P1.dat");
    ode_P1.Solve();

    //Test Problem 2
    SecondOrderOde P2(1,3,-4,model_prob_2_rhs,0,M_PI);
    BoundaryConditions bcP2;
    bcP2.SetLhsNeumann(-5);
    bcP2.SetRhsDirichlet(4);

    BvpOde ode_P2(&P2, &bcP2, 1001);
    ode_P2.SetFileName("Results_P2.dat");
    ode_P2.Solve();

    return 0;
}