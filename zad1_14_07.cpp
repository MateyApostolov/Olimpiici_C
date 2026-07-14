#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
const long long INF = 1e18 + 1;
long long nc[maxn], dp[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> nc[i];
    }
    for(int i = 2; i <= n; i++) {
        dp[i] = INF;
        for(int x = max(1, i - k); x < i; x++) {
            dp[i] = min(dp[i], abs(nc[x] - nc[i]) + dp[x]);
        }
    }
    cout << dp[n];
    return 0;
}
