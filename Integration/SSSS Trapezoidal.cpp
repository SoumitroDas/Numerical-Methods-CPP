//Trapezoidal Method
#include<iostream>
#include<cmath>
using namespace std;
double f(double x)       { return pow(x,2);}
int main()
{
    int n,i;   
    d:   
    double a,b,h,s=0,in=0;   
    cout<<"Enter the limits of integration,\nInitial limit,a=";   
    cin>>a;
    cout<<"Final limit, b=";
    cin>>b;
    cout<<"Enter the no. of subintervals, n=";          
    cin>>n;   
    double x[n+1],y[n+1]; 
    
    h=(b-a)/n;              
    for (i=0;i<=n;i++)           
    {                  
        x[i]=a+i*h;           
        y[i]=f(x[i]);
        if(i!=0 && i!=n)
        s+=h*y[i];
    }
    in=h/2.0*(y[0]+y[n])+s;      
    cout<<"The definite integral  is "<<in<<endl;
    double ac= (pow(b,3) - pow(a,3))/3;
    double p= (fabs((ac-in)/ac))*100;
    cout<<"The percentage error="<<p<<" %"<<endl;
    int l;
    cout<<"Do you like to calculate for other limits? if yes, press 1 or else any"<<endl;
    cin>>l;
    if(l==1)
    goto d;
  return 0;
}

