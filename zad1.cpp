#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int maxn = 1e4 + 1;
int nc[maxn], mask[maxn], dp[maxn][maxn];
bool ispr[maxn];
vector<int> primes;
vector <int> can[maxn];

void eratosten() {
    for(long long d = 2; d < maxn; d++) {
        if(ispr[d]) continue;
        for(long long h = d * d; h < maxn; h += d) {
            ispr[h] = true;
        }
    }
}

int main () {
    ///eratosten();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   /* for(int i = 2; i < maxn; i++) {
        if(!ispr[i]) primes.push_back(i);
    }*/
    int n, p = 0, ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> nc[i];
        /*int h = 0, c = nc[i];
        while(c > 1) {
            while(c % primes[h] == 0) {
                c /= primes[h];
                if(can[nc[i]][can[nc[i].size()] - 1] != primes[h]) can[nc[i]].push_back(primes[h]);
            }
            h++;
        }*/
    }
    for(int i = 1; i <= n; i++) {
        dp[i][1] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int k = 1; k <= nc[i]; k++) {
            if(nc[i] % k != 0) continue;
            for(int j = i; j <= n; j++) {
                if(nc[j] % (k + 1) != 0) continue;
                dp[j][k + 1] = (dp[j][k + 1] + dp[i][k]) % mod;
            }
        }

    }
    for(int i = 1; i <= n; i++) {
        cout << dp[i][nc[i]] << ' ';
        ans += dp[i][nc[i]];
    }
    cout << '\n';
    cout << ans + n;
    return 0;
}
