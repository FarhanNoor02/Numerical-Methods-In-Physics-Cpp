#include <iostream>
#include<cmath>
#include<fstream>
using namespace std;
double f(double x){
    return exp(-x)*sin(x);
}

double Df_f(double x, double h){
    double del=-f(x+2*h)+4*f(x+h)-3*f(x);
    return del/(2*h);
}

double Df_b(double x, double h){
    return (3*f(x)-4*f(x-h)+f(x-2*h))/(2*h);
}

int main(){
     double l=-5,u=5;
     ofstream fout("3-point_derivative.dat");
     fout<<l<<" "<<Df_f(l,0.01)<<endl;
    for(double x=l+0.01;x<=u-0.01;x+=0.01){
        fout<<x<<" "<<Df_f(x,0.01)<<endl;
    }
    fout<<u<<" "<<Df_b(u,0.01)<<endl;

    return 0;
}
