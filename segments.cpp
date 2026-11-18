#include <bits/stdc++.h>
using namespace std;

int main () {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a > b) swap(a, b);
    if(c > d) swap(c, d);
    if(a > d || b < c) cout << -1;
    else {
        if(a >= c && b <= d) cout << b - a;
        else if(c >= a && d <= b) cout << d - c;
        else if(a < c) cout << b - c;
        else if(c < a) cout << d - a;
    }

    return 0;
}
