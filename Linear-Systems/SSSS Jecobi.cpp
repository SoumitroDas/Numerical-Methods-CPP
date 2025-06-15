//Jacobi
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
    cout.precision(4);
    cout.setf(ios::fixed);
    int k,i,j,n;
    cout<<"\nEnter the no. of equations\n";
    cin>>n;                  
    double a[n][n+1];           
    double x[n];
double x1[n];               
double r[n];
    double eps,temp;
    cout<<"\n Enter the elements of the augmented matrix row-wise:\n";
    for (i=0;i<n;i++)
        for (j=0;j<=n;j++)
            cin>>a[i][j];
cout<<"\n The matrix you have entered is\n";
            for (i=0;i<n;i++)
            {
            for (j=0;j<=n;j++)
            cout<<a[i][j]<< setw(10);
            cout<<"\n";
}
cout<<"\n";
    cout<<"\n Enter the initial values of the variables:\n";
    for (i=0;i<n;i++)
        cin>>x[i];
    cout<<"\n Enter the accuracy upto which you want the solution:\n";
    cin>>eps;
    for (i=0;i<n-1;i++)                   
        for (k=i+1;k<n;k++)
            if (abs(a[i][i])<abs(a[k][i]))
                for (j=0;j<=n;j++)
                {
                    temp=a[i][j];
                    a[i][j]=a[k][j];
                    a[k][j]=temp;
                }
    cout<<"\n The matrix after pivoting\n";
    cout<<"\n----------------------------------------------------------------------\n";
    for (i=0;i<n;i++)
    {
    for(j=0;j<=n;j++)
    {
    cout<<a[i][j]<<setw(10);
}
cout<<"\n";
}
cout<<"\n";

    cout<<"\n----------------------------------------------------------------------";
    do                          
    {
        for (i=0;i<n;i++)               
        {
          x1[i]=x[i];
  r[i]=(a[i][n]/a[i][i]);
            for (j=0;j<n;j++)
            {
                if (j!=i)
                r[i]=r[i]-(a[i][j]/a[i][i]*x[j]);
            }
       
        for (i=0;i<n;i++)
        {
        x[i]=r[i];
   }
    }
} while (fabs(x1[0]-x[0])>eps||fabs(x1[1]-x[1])>eps||fabs(x1[2]-x[2])>eps);

    cout<<"\n The solution is as follows:\n";
    for (i=0;i<n;i++)
        cout<<"\n x["<<i<<"]="<<x[i];       
    return 0;
}

