#include <iostream>
#include<cmath>
#define e 0.00001 //tolerance, upto which root is to be found

using namespace std;
//define function f(x)=0:
double func(double x){
    return pow(x,3)-x*x+2;
}
//define derivative of f(x):
double fder(double x){
    return 3*x*x-2*x;
}
//newton raphson algortihm: x1=x0-f(x0)/f ' (x0):
void NR(double x){
    double  h=func(x)/fder(x);
    while(abs(h)>=e){
        h=h=func(x)/fder(x);
        x=x-h;
    }
    cout<<x;
}

int main(){
   //call the void function by passing an initial guess:
    NR(1); //here we take 1 as x0

    return 0;
}

