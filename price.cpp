#include <bits/stdc++.h>
using namespace std;

const long long maxs = 1e18;
const int maxn = 5 * 1e5 + 1;
const int maxk = 101;
int nc[maxn];

int main () {
    long long n, k, ans = 0;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> nc[i];
    }
    vector<long long> dp (k + 1, maxs);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        vector<long long> hdp (k + 1, maxs);
        for(int j = 0; j <= k; j++) {
            if(j > 0) hdp[j] = min(hdp[j], dp[j - 1] + (j % 2 == 0 ? nc[i] : -nc[i]));
            hdp[j] = min(hdp[j], dp[j] + (j % 2 == 0 ? nc[i] : -nc[i]));
        }
        dp = hdp;
    }
    for(int j = 0; j <= k; j++) {
        ans = min(ans, dp[j]);
    }
    cout << ans;
    return 0;
}
