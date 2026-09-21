#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 1, MAXK = 5e2 + 1;
long long x[MAXN], l, d;
int lo[MAXN], hi[MAXN], mn[MAXN];
int dp[MAXK][MAXN], n, k, a = 1, b = 1, p = 1;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k >> l;
    x[1] = 0;
    for(int i = 2; i <= n; i++) {
        cin >> d;
        x[i] = x[i - 1] + d;
    }
    for(int i = 1; i <= n; i++) {
        while(x[i] - x[a] > l) a++;
        lo[i] = a;
        while(b + 1 <= n && x[b + 1] - x[i] <= l) b++;
        hi[i] = b;
    }
    for(int i = 1; i <= n; i++) {
        while(hi[p] < i) p++;
        mn[i] = lo[p];
    }
    for(int j = 1; j <= k; j++)
        for(int i = 1; i <= n; i++)
            dp[j][i] = max(dp[j - 1][mn[i] - 1] + i - mn[i] + 1, max(dp[j][i - 1], dp[j - 1][i]));
    cout << dp[k][n];
    return 0;
}

