#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e12 + 39;

int main () {
    long long n, m, i = 1;
    cin >> n >> m;
    long long ans = 0;
    for(long long r = 1; r <= n; r++) {
        for(long long c = 1; c <= m; c++) {
            long long br = 0;
            br += min(r - 1, c - 1);
            br += min(r - 1, m - c);
            br += min(n - r, m - c);
            br += min(n - r, c - 1);
            ans = (ans + (br + 4) * i) % MOD;
            i++;
        }
    }
    cout << ans;
    return 0;
}
