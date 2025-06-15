//Modified Euler's Method
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double df(double x, double y) {return x/y;}

int main()
{
   double e,x0,x1,y0,x,y1,dy1,dy2,dy,yn,h,n;   
   cout<<"\nEnter the initial values of x and y respectively:\n";
   cin>>x0>>y0; 

   g:                 
   cout<<"\nEnter the value of x for which you would like to find y:\n";
   cin>>x;
   cout<<"\nEnter the no of subdivisin,n:\n";
   cin>>n;
   h=(x-x0)/n;
   //cout<<"\nEnter the desired accuracy"<<endl;
   //cin>>e;                      
   cout<<"x"<<setw(20)<<"y"<<setw(20)<<"hy"<<setw(20)<<"y*"<<setw(20)<<"hy_new"<<setw(20)<<"hyavg"<<setw(20)<<"y_n+1"<<endl;
   cout<<"--------------------------------------------------------------------------------------------------\n";  
   //while(fabs(x-x0)>=e)
for(int i=0;i<n;i++)
{  
       dy1=df(x0,y0);       
       y1=y0+h*dy1;
      x1=x0+h;         
       dy2=df(x1,y1);      
       dy=((dy1+dy2)*h)/2.0;       
       yn=y0+dy;           
       cout<<x0<<setw(20)<<y0<<setw(20)<<dy1<<setw(20)<<y1<<setw(20)<<dy2<<setw(20)<<dy<<setw(20)<<yn<<endl;
       x0=x0+h;           
       y0=yn;              
   }
   cout<<x0<<setw(20)<<y0<<endl;
   cout<<"The approximate value of y at x="<<x<<" is "<<y0<<endl;   
    double ac=sqrt(1+pow(x,2));
    double p=fabs((ac-y0)/ac)*100;
    cout<<"\nThe Percentage Error of the solution is ="<<p<<endl;
    cout<<"\nDo you want to calculate for other limits? or interval? if yes press 1 or press 0"<<endl;
    int z;
    cin>>z;
    if(z==1)
    goto g;
  
    return 0;
}

