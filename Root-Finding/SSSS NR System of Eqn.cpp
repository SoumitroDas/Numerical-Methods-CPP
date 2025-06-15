//NR for System of Equations
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

double f(double x,double y)
{return pow((x-1),2)+pow((y-1),2)-1;}
double g(double x,double y)
{return y-1;}

double fx(double x, double y)
{return 2*(x-1);}
double fy(double x,double y)
{return 2*(y-1);}
double gx(double x,double y)
{return 0;}
double gy(double x,double y)
{return 1;}

int main()
{  
    cout.precision(5);
cout.setf(ios::fixed);
    double e,x,y,x1,y1,f1,f2;
cout<<"\nEnter the desired accuracy"<<endl;
cin>>e;
a:
cout<<"\nEnter two initial guesses"<<endl;
cin>>x>>y;

while(fabs(x-x1)>=e || fabs(y-y1)>=e)
{
x1=x;
y1=y;
double j11=fx(x,y);
double j12=fy(x,y);
double j21=gx(x,y);
double j22=gy(x,y);

double d=j11*j22-j21*j12;
        
         if(d==0)
         {cout<<"\nThe system is niot convergent in the range ,please enter different initial approximations"<<endl;
          goto a; }
    f1=f(x,y);
f2=g(x,y);
double h=(j22*f1-j12*f2)/d;
double k=(-j21*f1+j11*f2)/d;
x-=h;
y-=k;
}
cout<<"The approximate solution of the system is \nx="<<x<<"\ny="<<y<<endl;
return 0;
}

