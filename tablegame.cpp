#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int maxn = 5e2 + 1;
int d2[maxn][maxn];
map<int, int> dp[maxn][maxn];


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> d2[i][j];
            d2[i][j] = __gcd(d2[i][j], k);
        }
    }
    dp[1][1][d2[1][1]] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(d2[i][j] == -1) continue;
            for(auto [nod, cnt] : dp[i - 1][j]) {
                int hnod = __gcd(1LL * nod * d2[i][j], 1LL * k);
                dp[i][j][hnod] = (dp[i][j][hnod] + cnt) % mod;
            }
            for(auto [nod, cnt] : dp[i][j - 1]) {
                int hnod = __gcd(1LL * nod * d2[i][j], 1LL * k);
                dp[i][j][hnod] = (dp[i][j][hnod] + cnt) % mod;
            }
        }
    }
    cout << dp[n][n][k];
    return 0;
}
