#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    long long a, n;
    for(int i = 0; i < t; i++) {
        cin >> a >> n;
        if(a < n) {
            cout << min(a, (a ^ n)) << '\n';
            continue;
        }
        long long k1 = (a + n - 1) / n, k2 = a / n;
        long long b1 = ((n * k1) ^ a), b2 = ((n * k2) ^ a);
        long long b = min(b1, b2);
        cout << b << '\n';
    }

    return 0;
}
