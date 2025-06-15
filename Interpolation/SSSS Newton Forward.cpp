//Newton Forward
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
cout.precision(5);
cout.setf(ios::fixed);
int n,i,j;
cout<<"Enter the number of set of values\n"<<endl;
cin>>n;
double x[n],y[n][n];
cout<<"Enter the values of X\n"<<endl;
for(i=0;i<n;i++)
cin>>x[i];
cout<<"Enter the values of Y\n"<<endl;
for(i=0;i<n;i++)
cin>>y[i][0];
   for(j=1;j<n;j++)
{
   for(i=0;i<n;i++)
{
y[i][j]= y[i+1][j-1]-y[i][j-1];
}
}
cout<<"The Forward difference Table\n"<<endl;
cout<<"x"<<setw(10)<<"y"<<setw(10);
for(i=1;i<n;i++)
cout<<"d"<<i<<"y"<<setw(10);
cout<<"\n----------------------------------------------------\n";
for(i=0;i<n;i++)
{cout<<x[i]<<setw(10);
for(j=0;j<n-i;j++)
{cout<<y[i][j];
cout<<setw(10);
}
cout<<"\n";
}
    double x1,h,u,s=y[0][0],t=1;
    cout<<"Enter the value of x for which y is needed to be calculated"<<endl;
    cin>>x1;
    h=x[1]-x[0];
    u=(x1-x[0])/h;
    for(j=1;j<n;j++)
    {
    t=t*(u-j+1)/j;
    s+=t*y[0][j];
}
cout<<"The value of y at x="<<x1<<"is approx.="<<s<<endl;
return 0;
}

