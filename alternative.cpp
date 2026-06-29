#include <bits/stdc++.h>
using namespace std;

long long nc[60];

int main () {
    long long n, c, ans = 0, x = 60;
    cin >> n;
    nc[0] = 1;
    for(int i = 1; i < 64; i++) {
        if(i % 2 != 0) {
            nc[i] = 2 * nc[i - 1];
        } else {
            nc[i] = 2 * nc[i - 1] + 1;
        }
    }
    while(n > 0) {
        if(x == 0) {
            cout << -1;
            return 0;
        }
        for(int i = x - 1; i >= 0; i--) {
            if(nc[i] <= n) {
                x = i;
                break;
            }
        }
        n -= nc[x];
        ans++;
    }
    cout << ans;
    return 0;
}
