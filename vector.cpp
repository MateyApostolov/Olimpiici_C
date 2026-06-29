#include <bits/stdc++.h>
using namespace std;

int main () {
    int t, x1, y1, x2, y2, a, b;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> a >> b;
        int X = x2 - x1, Y = y2 - y1;
        if(X < 0 || Y < 0 || a + 1 < X || b + 1 < Y) {
            cout << 0 << '\n';
            continue;
        }
        cout << (a - X + 1) * (b - Y + 1) << '\n';
    }

    return 0;
}
