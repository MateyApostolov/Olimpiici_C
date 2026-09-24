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
        }
    }
    if(d2[1][1] != -1) {
        dp[1][1][d2[1][1]] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(d2[i][j] == -1) continue;
            if(i == 1 && j == 1) continue;
            map <int, int> hdp;
            if(i > 1 && d2[i - 1][j] != -1) {
                for(auto    [nod, cnt] : dp[i - 1][j]) {
                    int hnod = __gcd(nod, d2[i][j]);
                    hdp[hnod] = (hdp[hnod] + cnt) % mod;
                }
            }
            if(j > 1 && d2[i][j - 1] != -1) {
                for(auto [nod, cnt] : dp[i][j - 1]) {
                    int hnod = __gcd(nod, d2[i][j]);
                    hdp[hnod] = (hdp[hnod] + cnt) % mod;
                }
            }
            if(!hdp.empty()) dp[i][j] = hdp;
        }
    }
    cout << dp[n][n][k];
    return 0;
}
