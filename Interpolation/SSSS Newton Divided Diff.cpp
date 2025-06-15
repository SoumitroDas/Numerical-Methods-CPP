//Newton's Divided Difference
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
cout.precision(6);
cout.setf(ios::fixed);
int i, j, k, n;
cout<<"Enter the number of values to be entered\n";
cin>>n;
double x[n], y[n][n];
cout<<"Enter the of values of x\n";
for(i=0; i<n; i++)
cin>>x[i];
cout<<"Enter the of values of y\n";
for(i=0; i<n; i++)
cin>>y[i][0];
for(j=1; j<n; j++)
{
for(i=0; i<n-j; i++)
{
y[i][j]=(y[i+1][j-1]-y[i][j-1])/(x[i+j]-x[i]);
}
}
cout<<"\nThe Divided difference table is as follows:\n\n";
cout<<"x"<<setw(20)<<"y"<<setw(20);
for(i=1; i<n; i++)
cout<<"d"<<i<<"y"<<setw(20);
cout<<"\n-------------------------------------------------------\n";
k=n;
for(i=0; i<n; i++)
{
cout<<x[i]<<setw(20);
for(j=0; j<k; j++)
{
cout<<y[i][j]<<setw(20);
}
cout<<"\n";
k--;
}
double xn, sum=y[0][0], temp=1.0;
cout<<"Enter the values of x at which y to be calculated\n";
cin>>xn;
for(j=1; j<n; j++)
{
temp=temp*(xn-x[j-1]);
sum=sum+temp*y[0][j];
}
cout<<"The value of y at x="<<xn<<" is: "<<sum<<endl;
return 0;
}

