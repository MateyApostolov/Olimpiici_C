#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e2 + 1;
const int INF = INT_MAX;

int n, s;
long long h[maxn], p[maxn];
int mm[2][maxn][maxn][maxn];

int dp(int u, int i, int j, int last){
    long long H;
    if(i < 0) return 0;
    if(mm[u][i][j][last] != 0) return mm[u][i][j][last] - 1;
    if (u == 1) H = p[last];
    else H = h[last];
    int r = dp(u, i - 1, j, last);
    if(h[i] <= H) r = max(r, dp(0, i - 1, j, i) + 1);
    if(j > 0 && p[i] <= H) r = max(r, dp(1, i - 1, j - 1, i) + 1);
    mm[u][i][j][last] = r + 1;
    return r;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> h[i] >> p[i];
    h[n] = INF;
    cout << dp(0, n - 1, s, n) << "\n";
}
