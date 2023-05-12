#include <iostream>
#include<cmath>
#define e 0.0001

using namespace std;

double func(double x){
    return x*cos(x)+sin(x);
}

void bisec(double a, double b){
    if(func(a)*func(b)>=0){
        cout<<"root is not bracketed"<<endl;

    }
    double c;
    while((b-a)>=e){
        c=(b+a)/2;
        if(func(c)==0){
            break;
        }
        else if(func(c)*func(a)<0){
            b=c;
        }
        else{
            a=c;
        }
    }
    cout<<c;
}

int main(){

    double m,n;
    cout<<"enter [a,b] : "<<endl;
    cin>>m>>n;
    bisec(m,n);

    return 0;
}

