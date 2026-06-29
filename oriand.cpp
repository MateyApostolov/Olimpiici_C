#include <bits/stdc++.h>
using namespace std;

int main () {
    unsigned long long n, k, m, r = -1, mmd, st1, st0, ans = 0;
    cin >> n >> k;
    mmd = pow(2, k);
    mmd--;
    long long nc[n];
    for(int i = 0; i < n; i++) cin >> nc[i];
    for(int l = 0; l < n - 1; l++) {
        m = l;
        st1 = nc[m];
        while(m + 1 < n && st1 != mmd) {
            m++;
            st1 = st1 | nc[m];
        }
        if(m == n - 1) break;
        r = m + 1;
        st0 = nc[r];
        while(r < n && st0 != 0) {
            r++;
            st0 = st0 & nc[r];
        }
        if(r == n) break;
        ans += n - r;
    }
    cout << ans;
    return 0;
}
