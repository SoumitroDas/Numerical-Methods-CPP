//Lagrange

#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main()

{

 cout.precision(7);

 cout.setf(ios::fixed);

 int i, j, k, n;

 cout<<"Enter the number of values to be entered\n";

 cin>>n;

 double x[n], y[n];

 cout<<"Enter the of values of x\n";

 for(i=0; i<n; i++)
 cin>>x[i];

 cout<<"Enter the of values of y\n";

 for(i=0; i<n; i++)
 cin>>y[i];

 double xn, s=0;

a:

 cout<<"Enter the values of x at which y to be calculated\n";

 cin>>xn;

 for(i=0; i<n; i++)
 {

double t=1.0;

 for(j=0; j<n; j++)
 {

 if(j!=i)
 t=t*((xn-x[j])/(x[i]-x[j]));

 }

 s+=t*y[i];

 }

 cout<<"The value of y at x= "<<xn<<" is: "<<s<<endl;

int z;
cout<<"Wanna check for another value? if yes press 1 or else any"<<endl;
cin>>z;
if(z==1)
goto a;

 return 0;

}

