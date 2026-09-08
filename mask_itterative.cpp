#include <bits/stdc++.h>
using namespace std;

const int maxc = 1e4 + 1;
const int maxm = 1e7 + 1;
int x[maxc], y[maxc], dist[maxc][maxc], dp[maxm];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int val = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            dist[i][j] = val;
            dist[j][i] = val;
        }
    }
    dp[0] = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(!(mask & (1 << i)) && !(mask & (1 << j))) {
                    int ndp = mask | (1 << i) | (1 << j);
                    dp[ndp] = max(dp[ndp], dp[mask] + dist[i][j]);
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << ".000";
    return 0;
}

