//Gouse Elimination Method
#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

int main()
{
    int i,j,k,n;
    cout.precision(5);
    cout.setf(ios::fixed);
    cout<<"Enter the size of the system\n";
    cin>>n;
    float a[n][n+1], x[n];
     cout<<"Enter the elements of co efficients row wise\n";
     for(i=0;i<n;i++)
        for(j=0;j<=n;j++)
        cin>>a[i][j];

     for(i=0;i<n;i++)
     {
     for(k=i+1;k<n;k++)
     {
     if(abs(a[i][i])<abs(a[k][i]))
     {
     for(j=0;j<=n;j++)
     {
  	  double t=a[i][j];
  	  a[i][j]=a[k][j];
  	  a[k][j]=t;
     }
}
}
}
//pivot
cout<<"\nMetrix after Pivotization"<<endl;
for (i=0;i<n;i++)
     {
      for (j=0;j<=n;j++)
       cout<<a[i][j]<<setw(16);
       cout<<"\n";
     }
     //Gauss
      for(i=0;i<n-1;i++)
     {
     for(k=i+1;k<n;k++)
     {
     {
     double t=a[k][i]/a[i][i];
     for(j=0;j<=n;j++)
  	 {
  	   a[k][j]=a[k][j]-t*a[i][j];
  }
}
}
}
cout<<"\nMetrix after elemination"<<endl;
for (i=0;i<n;i++)
     {
      for (j=0;j<=n;j++)
       cout<<a[i][j]<<setw(16);
       cout<<"\n";
     }
    
     for(i=n-1;i>=0;i--)
     {
         if(a[i][i]==0)
         {
             cout<<"Inconsistence detected\n";
             exit(0);
         }
         else
         {
             x[i]=a[i][n];
             for(j=i+1;j<n;j++)
                if(j!=i)
                 x[i]=x[i]-a[i][j]*x[j];
             x[i]=x[i]/a[i][i];
         }
     }
   
     cout<<"Values"<<endl;
     for(i=0;i<n;i++)
        cout<<x[i]<<endl;
return 0;
}

