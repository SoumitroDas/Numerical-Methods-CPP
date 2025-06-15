//Simpson's 3/8th Rule for Evaluation of Definite Integrals
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double f(double x) {return 1/(1+pow(x,2));}
int main() {
    cout.precision(6);      
    cout.setf(ios::fixed);
    int n,i;          
    g:
    double a,b,c,h,s=0,t=0;
    cout<<"\nEnter the interval of integration,\n\nLower limit,a= ";
    cin>>a;
    cout<<"\nUpper limit, b="; 
    cin>>b;
    cout<<"\nEnter the no. of subintervals\n";
    cout<<"Please enter a number that is multiple of 3\n";
    cin>>n;
    n=3*n;
    double x[n+1],y[n+1];
    h=(b-a)/n;   
    for (i=0;i<n+1;i++){                
        x[i]=a+i*h;              
        y[i]=f(x[i]);   
    }
    for (i=1;i<n;i++)
    {
        if (i%3==0)
            s+=2*y[i];
        else
            s+=3*y[i];
    }
    t=3*h/8*(y[0]+y[n]+s);
    cout<<"\nThe definite integral  is "<<t<<"\n"<<endl;
    double ac=atan(b)-atan(a);
    double p=fabs((ac-t)/ac)*100;
    cout<<"\nThe Percentage Error of the solution is ="<<p<<endl;
    cout<<"\nDo you want to calculate for other limits? or interval? if yes press 1 or press 0"<<endl;
    int z;
    cin>>z;
    if(z==1)
    goto g;
    else
    return 0;
}

