// curve_fit
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
cout.precision(6);
cout.setf(ios::fixed);
int i,j,k,n,m;
cout<<"\nEnter the number of points to be entered\n";
cin>>m;
double p[m], q[m], temp, t;
cout<<"\nEnter the x values\n";
for(i=0; i<m; i++)
{
cin>>p[i];
}
cout<<"\nEnter the y values\n";
for(i=0; i<m; i++)
{
cin>>q[i];
}
n=3;
double a[n+1][n+2],x[n+1];
for(i=0; i<=n; i++)
{
    for(j=0; j<=n; j++)
{
a[i][j]=0;
for(k=0;k<m;k++)
{
a[i][j]=a[i][j]+pow(p[k],(i+j));
}
}
a[i][n+1]=0;   // augmented part
for(k=0;k<m;k++)
{
a[i][n+1]=a[i][n+1]+pow(p[k],i)*q[k];
}
}
n=n+1; 
//Do pivoting
for(i=0; i<n-1; i++)
{
for(k=i+1; k<n; k++)
{
if(fabs(a[i][i])<fabs(a[k][i]))
{
for(j=0; j<=n; j++)
{
temp=a[i][j];
a[i][j]=a[k][j];
a[k][j]=temp;
}
}
}
}
for(k=0; k<n-1; k++)
{
for(i=k+1; i<n; i++)
{
t=a[i][k]/a[k][k];
for(j=0; j<=n; j++)
{
a[i][j]=a[i][j]-t*a[k][j];
}
}
}
for(i=n-1; i>=0; i--)
{
x[i]=a[i][n];
for(j=i+1; j<n; j++) 
{
if(j!=i)
x[i]=x[i]-a[i][j]*x[j];
}
x[i]=x[i]/a[i][i];
}
cout<<"\nThe values of the coefficients are\n";
for(i=0; i<n; i++)
{
cout<<x[i]<<endl;
}
cout<<"\nThe required polynomial is\n";
cout<<"y="<<x[0]<<"+"<<x[1]<<"x+"<<x[2]<<"x^2+"<<x[3]<<" x^3"<<endl;
return 0;
}

