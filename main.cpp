#include <iostream>
#include<cmath>
#include<fstream>

using namespace std;
//dy/dt=f(y,t):
double f(double y, double t)
{
    return exp(-0.1*t)-y;
}

void rk4(double y_0,double t_0, double t_f, double n) //y_0 =y(t_0)
{
    ofstream fout("rk4.dat");
    double k1,k2,k3,k4,sol=y_0,h;
    h=(t_f - t_0)/n;
    for(double t=t_0;t<=t_f;t+=h){

        k1=h*f(sol, t);
        k2=h*f(sol+k1/2 , t+h/2);
        k3=h*f(sol+k2/2,t+h/2);
        k4=h*f(sol+k3,t+h);
        sol =sol+(k1+2*k2+2*k3+k4)/6;
        fout<<t<<" "<<sol<<endl;
    }

}

int main()
{

    rk4(0.5,0,5,100);

    return 0;

}
