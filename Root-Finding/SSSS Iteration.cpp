//Iteration
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double f(double x)
{return (1+cos(x))/3;}
double c(double x)
{return (-sin(x))/3;}int main()
{
cout.precision(5);
cout.setf(ios::fixed);
double e,x,x1;
cout<<"\nEnter the desired acuracy"<<endl;
cin>>e;
a:
    cout<<"\nEnter the initial approximation"<<endl;
    cin>>x1;
if(fabs(c(x1))<1)
{
  do
  {   
       x=x1;
     x1=f(x);
     if(f(x1)==0)
{
cout<<"\nThe root of the equation is="<<x1<<endl;
break;
}   
  }while(fabs(x-x1)>=e);
}
else
{
    cout<<"\nEnter different initial guess"<<endl;
goto a;
}
cout<<"\nThe root of the equation is="<<x1<<"(Approx.)"<<endl;
return 0;
}

