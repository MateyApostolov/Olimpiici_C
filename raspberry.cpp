#include <bits/stdc++.h>
using namespace std;

const int maxn = 502;
long long d2[maxn][maxn], dp[maxn][maxn], maxrc[maxn][maxn];

int main () {
    long long n, m, ans = 0;
    cin >> n >> m;
    for(int r = 0; r <= n; r++) {
        for(int c = 0; c <= m; c++) {
            if(r == n || c == m) dp[r][c] = -1001;
            else cin >> d2[r][c];
        }
    }
    for(int r = n - 1; r >= 0; r--) {
        for(int c = m - 1; c >= 0; c--) {
            maxrc[r][c] = max(d2[r][c], max(maxrc[r + 1][c], maxrc[r][c + 1]));
            dp[r][c] = max(d2[r][c], max(maxrc[r][c + 1], maxrc[r + 1][c]) + d2[r][c]);
            ans += dp[r][c];
            maxrc[r][c] = max(maxrc[r][c], dp[r][c]);
        }
    }
    cout << ans;
    return 0;
}
