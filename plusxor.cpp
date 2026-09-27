#include <bits/stdc++.h>
using namespace std;

int main () {
    unsigned long long a, b, dhc, x, y;
    cin >> a >> b;
    dhc = (a - b) / 2;
    x = dhc;
    y = a - dhc;
    if((x ^ y) == b) {
        cout << x  << ' ' << y;
    } else {
        cout << -1;
    }
    return 0;
}
