//RUNGE-KUTTA 4th Order Method
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double df(double x, double y) {return pow(x,2)/pow(y,2);}

int main()
{
    int n,i;  
    double x,x0,y0,xn,yn,h,k1,k2,k3,k4;           
    cout.precision(5);          
    cout.setf(ios::fixed);              
    cout<<"Enter the initial condition";
   cout<<"\nEnter the initial value of x & y respectively"<<endl;
   cin>>x0>>y0;
   g:                            
    cout<<"\nEnter the value of x for which you want to find the value of y"<<endl;  
    cin>>x;
    cout<<"\nEnter the number of steps n:\n";
    //cout<<"\nPlease enter a large value of \n";           
    cin>>n;
    h=(x-x0)/n;
    cout<<"x"<<setw(20)<<"y"<<setw(20)<<"yn"<<endl;
    cout<<"------------------------------------------------------\n";
    for(i=0;i<n;i++) 
    {  
    k1=h*df(x0,y0);
    k2=h*df(x0+h/2, y0+k1/2);
    k3=h*df(x0+h/2, y0+k2/2);
    k4=h*df(x0+h, y0+k3);
    yn=y0+(k1+2*k2+2*k3+k4)/6; 
cout<<x0<<setw(20)<<y0<<setw(20)<<yn<<endl;                            
   x0=x0+h;
y0=yn;	        
    }         
    cout<<"\n\nThe approximate value of y at x="<<x<<" is="<<y0<<endl;       
    double ac=cbrt(pow(x,3)+1);
    double p=fabs((ac-y0)/ac)*100;
    cout<<"\nThe Percentage Error of the solution is ="<<p<<endl;
    cout<<"\nDo you want to calculate for other limits? or interval? if yes press 1 or press 0"<<endl;
    int z;
    cin>>z;
    if(z==1)
    goto g;

    return 0;
}

