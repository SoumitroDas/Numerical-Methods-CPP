//Gaus-seidel
#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;

int main() {
    cout.precision(5);
    cout.setf(ios::fixed);
    int n;
    double e;
    char r;

    do {
        cout <<"Hello\nEnter the accuracy upto which you want the solution:\n";
        cin >> e;
        cout << "Enter the system size\n";
        cin >> n;

        vector<vector<double> > a(n, vector<double>(n + 1));
        vector<double> x(n, 0), y(n), z(n);

        cout <<"\nEnter the elements of the augmented matrix row-wise:\n";
        for (int i = 0; i < n; i++)
            for (int j = 0; j <= n; j++)
                cin >> a[i][j];

        // piv
        for (int i = 0; i < n - 1; i++)
            for (int k = i + 1; k < n; k++)
                if (abs(a[i][i]) < abs(a[k][i]))
                    for (int j = 0; j <= n; j++)
                        swap(a[i][j], a[k][j]);

        // convergence condi
        for (int i = 0; i < n; i++) {
            z[i] = fabs(a[i][i]);
            for (int j = 0; j < n; j++)
                if (i != j) z[i] -= fabs(a[i][j]);
            if (z[i] < 0) {
                cout << "\nDoesn't satisfy convergence.\n";
                goto skip;
            }
        }

        bool ok;
        do {
            ok = true;
            for (int i = 0; i < n; i++) {
                y[i] = x[i];
                x[i] = a[i][n];
                for (int j = 0; j < n; j++)
                    if (j != i) x[i] -= a[i][j] * x[j];
                x[i] /= a[i][i];
                if (fabs(x[i] - y[i]) > e) ok = false;
            }
        } while (!ok);

        cout << "\n The solution is as follows:\n";
        for (int i = 0; i < n; i++)
            cout << "x" << i + 1 << " = " << x[i] << endl;

        skip:
        cout << "\nIf you want to calculate for another system press 1 or else press any:";
        cin >> r;
    } while (r == '1');

    return 0;
}

