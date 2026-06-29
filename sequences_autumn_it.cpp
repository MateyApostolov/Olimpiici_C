#include <bits/stdc++.h>
using namespace std;

const int d7 = 1e9 + 7;
const int maxn = 2 * 1e6 + 1;
int dp[maxn], pref[maxn];


int main () {
    int n, k;
    cin >> n >> k;
    dp[0] = 1;
    pref[0] = 1;
    for(int i = 0; i <= n; i++) {
        int l = i - min(i, k), r = max(i - 1, 0);
        dp[i] = (pref[r] - (l > 0 ? pref[l - 1] : 0) + d7) % d7;
        pref[i] = (pref[i - 1] + dp[i]) % d7;
    }
    cout << dp[n];
    return 0;
}
