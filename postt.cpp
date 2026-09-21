#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
const int maxk = 5e2 + 1;

int lft[maxn], rght[maxn];
int range[maxn], diff[maxn], dp[maxn][maxk];
int p = 1, p1 = 1, p2 = 1, c;

int main () {
    int n, k, l;
    cin >> n >> k >> l;
    diff[1] = 0;
    for(int i = 2; i <= n; i++) {
        cin >> c;
        diff[i] = diff[i - 1] + c;
    }
    for(int i = 1; i <= n; i++) {
        while(diff[i] - diff[p1] > l) p1++;
        lft[i] = p1;
        while(p2 + 1 <= n && diff[p2 + 1] - diff[i] <= l) p2++;
        rght[i] = p2;
    }
    for(int i = 1; i <= n; i++) {
        while(rght[p] < i) p++;
        range[i] = lft[p];
    }
    for(int i = 1; i <= n; i++) {
        for(int hk = 1; hk <= k; hk++) {
            dp[i][hk] = max(dp[range[i] - 1][hk - 1] + i - range[i] + 1, max(dp[i - 1][hk], dp[i][hk - 1]));
        }
    }
    cout << dp[n][k];
    return 0;
}
