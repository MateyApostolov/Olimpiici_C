#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 1;

int main () {
    int n, sum = 0, t;
    cin >> n;
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        sum += b[i];
    }
    if(sum % 3 != 0) {
        cout << -1;
        return 0;
    }
    t = sum / 3;
    int dp[n + 1][sum + 1][sum + 1];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= sum; j++) {
            for(int k = 0; k <= sum; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= t; j++) {
            for(int k = 0; k <= t; k++) {
                if(dp[i - 1][j][k] == INF) continue;
                ///if(j + b[i] <= t) {
                dp[i][j + b[i]][k] = min(dp[i][j + b[i]][k], dp[i - 1][j][k] + (a[i] != 1));
               /// }
               /// if(k + b[i] <= t) {
                dp[i][j][k + b[i]] = min(dp[i][j][k + b[i]], dp[i - 1][j][k] + (a[i] != 2));
                ///}
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + (a[i] != 3));
            }
        }
    }
    if(dp[n][t][t] == INF) cout << -1;
    else cout << dp[n][t][t];
    return 0;
}
