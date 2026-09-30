#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 1;
int h[maxn], p[maxn], dp[maxn][maxn];

int main () {
    int n, s, ans = 0;
    cin >> n >> s;
    for(int i = 0; i < n; i++) {
        cin >> h[i] >> p[i];
    }
    dp[1][0] = 1;
    for(int i = n - 1; i >= 0; i--) {
        for(int x = i + 1; x < n; x++) {
            for(int hs = 0; hs <= s; hs++) {
                if(h[x] >= h[i]) {
                    dp[i][hs] = max(dp[i][hs], dp[x][hs] + 1);
                } else if(h[x] >= p[i]){
                    dp[i][hs + 1] = max(dp[i][hs], dp[x][hs] + 1);
                }
            }
        }
    }
    for(int hs = 0; hs <= s; hs++) {
        if(hs <= s) ans = max(ans, dp[0][hs]);
    }
    cout << ans;
    return 0;
}
