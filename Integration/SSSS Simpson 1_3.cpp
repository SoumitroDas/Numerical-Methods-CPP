//Simpson's 1/3rd Rule for Evaluation of Definite Integrals
#include<iostream>
#include<cmath>
using namespace std;
double f(double x) {return 1/(1+x);}

int main()
{   cout.precision(5);      
    cout.setf(ios::fixed);
    int n,i; 
    d:        
    double a,b,c,h,s=0,t=0;
    cout<<"\nEnter the interval of integration,\n\nLower limit  a= ";
    cin>>a;
    cout<<"\nUpper limit, b=";               
    cin>>b;
    cout<<"\nEnter the no. of subintervals\n\n";   
    cout<<"\nPlease enter a number that is multiple of 2";      
    cin>>n;
    double x[n+1],y[n+1];
    h=(b-a)/n;                     
    for (i=0;i<n+1;i++)
    {                     
        x[i]=a+i*h;             
        y[i]=f(x[i]);
    }
    for (i=1;i<n;i+=2)
    {
        s=s+4.0*y[i];             
    }
    for (i=2;i<n-1;i+=2)
    {
        s=s+2.0*y[i];              
                                     
    }
    t=h/3.0*(y[0]+y[n]+s);  
    cout<<"\nThe definite integral  is "<<t<<"\n"<<endl;
    double ac= log(1+b) - log(1+a);
    double p= (fabs((ac-t)/ac))*100;
    cout<<"The percentage error="<<p<<" %"<<endl;
    int l;
    cout<<"Do you like to calculate for other limits? if yes, press 1 or else any"<<endl;
    cin>>l;
    if(l==1)
    goto d;
    return 0;
}
