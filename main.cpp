#include <iostream>
#include<cmath>
#include<fstream>

using namespace std;
//suppose we have y''+y'-6y=0
//let {y'=z ->z'=6y-z} this is our system of 1st order ode
double f1(double y,double z)
{
    return z;
}
double f2(double y,double z)
{
    return 6*y-z;
}

void RK4(double y_0,double z_0,double t_0,double t_f, double n)
{
    ofstream fout("RK4_2deg.dat");
    double k1,k2,k3,k4,l1,l2,l3,l4,h,s1=y_0,s2=z_0;
    h=(t_f -t_0)/n;
    for(double t=t_0;t<=t_f;t+=h){
        k1=h*f1(s1,s2);
        l1=h*f2(s1,s2);
        k2=h*f1(s1+0.5*k1,s2+0.5*l1);
        l2=h*f2(s1+0.5*k1,s2+0.5*l1);
        k3=h*f1(s1+0.5*k2,s2+0.5*l2);
        l3=h*f2(s1+0.5*k2,s2+0.5*l2);
        k4=h*f1(s1+k3,s2+l3);
        l4=h*f1(s1+k3,s2+l3);

        s1=s1+(k1+2*k2+2*k3+k4)/6;
        s2=s2+(l1+2*l2+2*l3+l4)/6;

        fout<<t<<" "<<s1<<" "<<s2<<endl;
    }

}

int main()
{

    RK4(3,1,0,1,100);

    return 0;
}
