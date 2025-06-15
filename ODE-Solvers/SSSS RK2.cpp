//RUNGE-KUTTA 4th Order Method for 2d system
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double df(double x, double y, double z) {return z;}
double dg(double x, double y, double z) {return -y;}

int main()
{
    int n,i;  
    double x,x0,y0,z0,xn,yn,zn,h,k1,k2,k3,k4,l1,l2,l3,l4;           
    cout.precision(5);          
    cout.setf(ios::fixed);              
    cout<<"Enter the initial condition";
cout<<"\nEnter the initial value of x , y & y' respectively"<<endl;
cin>>x0>>y0>>z0;          
g:                  
    cout<<"\nEnter the value of x for which you want to find the value of y & y'"<<endl;  
    cin>>x;
    cout<<"\nEnter the number of steps n:\n";
    //cout<<"\nPlease enter a large value of \n";           
    cin>>n;
    h=(x-x0)/n;
    cout<<"x"<<setw(20)<<"y"<<setw(20)<<"y'"<<setw(20)<<"yn"<<setw(20)<<"y'n"<<endl;
    cout<<"-------------------------------------------------------------------\n";
    for(i=0;i<n;i++) 
    {  
    k1=h*df(x0, y0, z0);
    l1=h*dg(x0, y0, z0);
    k2=h*df(x0+h/2, y0+k1/2, z0+l1/2);
    l2=h*dg(x0+h/2, y0+k1/2, z0+l1/2);
    k3=h*df(x0+h/2, y0+k2/2,z0+l2/2);
    l3=h*dg(x0+h/2, y0+k2/2,z0+l2/2);
    k4=h*df(x0+h, y0+k3, z0+l3);
    l4=h*dg(x0+h, y0+k3, z0+l3);
    yn=y0+(k1+2*k2+2*k3+k4)/6; 
    zn=z0+(l1+2*l2+2*l3+l4)/6;
cout<<x0<<setw(20)<<y0<<setw(20)<<z0<<setw(20)<<yn<<setw(20)<<zn<<endl;                      
        x0=x0+h;
y0=yn;
z0=zn;           
    }         
    cout<<"\n\nThe approximate value of y at x="<<x<<" is="<<yn<<endl;
cout<<"\n\nThe approximate value of y' at x="<<x<<" is="<<zn<<endl;       
    double ac1=sin(x);
    double p1=fabs((ac1-yn)/ac1)*100;
    cout<<"\nThe Percentage Error of the solution of y is ="<<p1<<endl;
   double ac2=cos(x);
    double p2=fabs((ac2-zn)/ac2)*100;
    cout<<"\nThe Percentage Error of the solution of y' is ="<<p2<<endl;
     cout<<"\nDo you want to calculate for other limits? or interval? if yes press 1 or press 0"<<endl;
    int z;
    cin>>z;
    if(z==1)
    goto g;
    else

  return 0;
}

