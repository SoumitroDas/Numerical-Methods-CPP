//Heat eqn

#include<iostream>

#include<iomanip>

#include<cmath>

using namespace std;

int main() 

{

    cout.precision(3);

    cout.setf(ios::fixed);

    double c, xi, ui, xf, uf, ut, tf, h, k, l;

    int i,j;

    cout << "Numerical solution of Heat equation using finite difference formula" << endl;

    cout << "Enter value of c: ";

    cin >> c;

    cout << "Enter initial x and corresponding u (1st boundary condition): "<<endl;

    cin >> xi >> ui;

    cout << "Enter final x and corresponding u (2nd boundary condition): "<<endl;

    cin >> xf >> uf;

    cout << "Enter final simulation time: "<<endl;

    cin >> tf;

    cout <<"Enter value of special subdivission "<<endl;

    

   

 //   do {

        int m;

        cin >>m;

       h=((xf - xi) / m);

       k=pow(h,2)/(2*c) ;

        l = c * (k / pow(h,2));

       //l=pow(alpha,2);//lemda=l

       // if (l >= 1) {

       //     cout << "Please enter new values of h and k such that lembda < 1 (lembda = c * (k / h^2)): ";

       // }

  //  }while (l >= 1);

//   cout<<" l="<<l<<endl;
 //   int m = static_cast<int>((xf - xi) / h);

//    int n = static_cast<int>((tf) / k);

   // int m = ((xf - xi) / h);

    int n = ((tf) / k) +1 ;

    cout<<"Spacial subdivision m="<<m<<"\nTimal Subdivision n="<<n<<endl<<"Corresponding h= "<<h<<"\n and \nk="<<k;

    double u[n + 1][m + 1];

    //boundary

    for (i = 0; i <= n; i++) {

        u[i][0] = ui;

        u[i][m] = uf;

    }

    //u(x,0)

    for ( j = 1; j < m; j++) {

        double x = xi + j * h;

        u[0][j] =sin(3.1416 * x);

      }  

    

    // Perform time-stepping for the heat equation

    for (i = 1; i <= n; i++) {

        for ( j = 1; j < m; j++) {

            u[i][j] = l * (u[i - 1][j - 1] + u[i - 1][j + 1]) + ((1 - 2*l) * u[i - 1][j]) ;

        }

    }

  int xp,tp,xs,ts,z;  

   do

  { 

    int p;

    cout << "\nSelect the output preference:\n";

    cout << "1. For specific x and t\n";

    cout << "2. For specific x with full spectrum of t\n";

    cout << "3. For specific t with full spectrum of x\n";

    cin >> p;

   if(p==1) {

           // Specific x and t

            double x_choice, t_choice;

            cout << "Enter specific x and t values: ";

            cin >> x_choice >> t_choice;

            xp=x_choice*m;

            tp=t_choice*n;

            cout << "u(" << x_choice << "," << t_choice << ") = " << u[tp][xp] << endl; //u(x,t) vs u(t,x)

    }

            

      else if(p==2)

  {            // Specific x with full spectrum of t

            double x_specific;

            cout << "Enter specific x value for the full spectrum of t: ";

            cin >> x_specific;

            xs=x_specific*m;

            for (int i = 0; i <= n; i++) {

                double t = i * k;

                cout << "u(" << x_specific << "," << t << ") = " << u[i][xs] << endl;

            }

       }

            

     else if(p==3)

           { // Specific t with full spectrum of x

            double t_specific;

            cout << "Enter specific t value for the full spectrum of x: ";

            cin >> t_specific;

            ts=t_specific*n/tf;

            for (int j = 0; j <= m; j++) {

                double x = xi + j * h;

                cout << "u(" << x << "," << t_specific << ") = " << u[ts][j] <<endl;

            }

           }

   cout<<"Do you want to calculate for another value press 1 else any"<<endl;

   cin>>z;

} while(z==1);

  return 0;

}

