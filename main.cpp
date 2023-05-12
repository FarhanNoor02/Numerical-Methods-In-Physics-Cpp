#include<iostream>
#include<cmath>
#include<fstream>

using namespace std;

double f(double x)
{
    return x*x*sin(x)+2;

}
double D2f_f(double x, double h)
{
    return (f(x+2*h)-2*f(x+h)+f(x))/(pow(h,2));
}
double D2f_c(double x,double h)
{
    return (f(x+h)+f(x-h)-2*f(x))/(pow(h,2));
}
double D2f_b(double x,double h)
{
    return (f(x-2*h)-2*f(x-h)+f(x))/(pow(h,2));
}

int main()
{
   double l=-5,u=5;
    ofstream fout("f-f''.dat");
    fout<<l<<" "<<D2f_f(l,0.01)<<endl;
    for(double x=+0.01;x<=u-0.01;x+=0.01){
        fout<<x<<" "<<D2f_c(x,0.01)<<endl;
    }
    fout<<u<<" "<<D2f_b(u,0.01)<<endl;

    return 0;
}
