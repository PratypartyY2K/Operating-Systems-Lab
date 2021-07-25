#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t; double a, b, c;
    double sin_theta;
    cin >> t;
    while(t--) {
        cin >> a >> b >> c;
        if (( a + b > c) && ( b + c > a) && ( c + a > b)) {
            if( ( a*a + b*b == c*c ) ) {
                sin_theta = min(a/c,b/c);
                cout << fixed << setprecision(6) << sin_theta << "\n";
            } 
            else if( ( b*b + c*c == a*a ) ) {
                sin_theta = min(c/a,b/a);
                cout << fixed << setprecision(6) << sin_theta << "\n";
            }
            else if( ( a*a + c*c == b*b ) ) {
                sin_theta = min(a/b,c/b);
                cout << fixed << setprecision(6) << sin_theta << "\n";
            }
            else {
                cout << "-1.000000\n";
            }
        }
    }
    return 0;
}
