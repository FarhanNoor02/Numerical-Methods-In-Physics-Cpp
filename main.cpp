#include <iostream>
#include<cmath>
#include<fstream>

using namespace std;
//trapezium rule:
double trap(double (func)(double), double a, double b, int n){
    double x,sum=0,del;
    int i;
    if(n==1){
        return 0.5*(b-a)*((func)(a)+(func)(b));
    }
    else if(n>1){
        del=(b-a)/n;
        sum+=(func)(a);
        for(i=0;i<=n;i++)
        {
            x+=del;
            sum+=2*(func)(x);
        }
        sum+=(func)(b);
        return sum*0.5*del;
    }
}
//user defined function:
double f1(double x){
    return pow(x,2);
}
double f2(double x){
    return 0.33*pow(x,3);
}
int main(){
//to print values of the integral for various values of n in a dat file
    ofstream fout("n.dat");
    for(double j=-10;j<=10;j+=0.01){
        fout<<j<<" "<<trap(f1,0,j,2000)<<" "<<f2(j)<<endl; // to write to the file
    }


    return 0;
}

