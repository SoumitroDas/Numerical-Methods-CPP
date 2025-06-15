//1(a) Bisection
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double f(double x)
{return 3*x-cos(x)-1;}
int main()
                       {                cout.precision(5);
cout.setf(ios::fixed);
double e,a,b,c,fa,fb,fc;
cout<<"\nEnter the desired accuracy"<<endl;
cin>>e;
g:
cout<<"\nEnter two initial guesses"<<endl;
cin>>a;
cin>>b;
fa=f(a);
    fb=f(b);   
if(fa*fb>0)
{
cout<<"\nInvalid initial guesses for Bisection Method"<<endl;
    cout<<"\nEnter different initial guesses"<<endl;
goto g;
} 
else
{
   while(fabs(a-b)>=e)
   {   
c=(a+b)/2;
    fa=f(a);
fb=f(b);
fc=f(c);
if(fc==0)
{
cout<<"\nThe root of the equation is="<<c<<endl;
break;
}
if(fb*fc>0)
{
   b=c;
}
else
{
   a=c;
}
   }
}
    cout<<"\nThe root of the equation is="<<c<<"(Approx.)"<<endl;
return 0;
}

