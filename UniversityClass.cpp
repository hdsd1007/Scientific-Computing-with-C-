//Assignment 7
#include "University.cpp"

int main(int argc, char *argv[])
{
    University su1;
    Graduate su2;
    Phd su3;
    su1.setFine(500);
    su2.setFine(800);
    su3.setFine(1500);
    su1.Tuition = 15000;
    su2.Tuition = 15000;
    su3.Tuition = 15000;


    std::cout << " The money owed by Undergraduate Student is = " << su1.MoneyOwed() << std::endl;
    std::cout << " The money owed by Graduate Student is = " << su2.MoneyOwed() << std::endl;
    std::cout << " The money owed by PhD Student is = " << su3.MoneyOwed() << std::endl;

    return 0;
}