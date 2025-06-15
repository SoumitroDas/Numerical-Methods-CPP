//Newton Rephson
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double f(double x)
{return 3*x-cos(x)-1;}
double fp(double x)
{return 3+sin(x);}
int main()
{
cout.precision(5);
cout.setf(ios::fixed);
double e,x,x1,fx,fxp;
cout<<"\nEnter the desired accuracy"<<endl;
cin>>e;
a:
cout<<"\nEnter the initial guess"<<endl;
cin>>x1;  
fxp=fp(x1);
    if(fxp==0)
    { cout<<"Please,enter different initial approximation other then pick point"<<endl;
goto a;
    }
    while(fabs(x-x1)>=e)
    {
    x=x1;
    fx=f(x);
    fxp=fp(x);
    x1=x-(fx/fxp);
    if(f(x1)==0)
{
cout<<"\nThe root of the equation is="<<x1<<endl;
break;
}
}
cout<<"\nThe root of the equation is="<<x1<<"(Approx.)"<<endl;
return 0;
}

