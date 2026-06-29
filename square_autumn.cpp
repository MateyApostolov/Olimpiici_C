#include <bits/stdc++.h>
using namespace std;

const int maxn = 3002;
char d2[maxn][maxn];
int dp1[maxn][maxn], dp2[maxn][maxn], dp3[maxn][maxn], dp4[maxn][maxn];

int main () {
    int n, m, ans = 0;
    cin >> n >> m;
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            cin >> d2[r][c];
        }
    }
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            dp1[r][c] = (dp1[r - 1][c - 1] + 1) * (d2[r][c] - '0');
            dp2[r][c] = (dp2[r - 1][c + 1] + 1) * (d2[r][c] - '0');
        }
    }
    for(int r = n; r >= 1; r--) {
        for(int c = m; c >= 1; c--) {
            dp3[r][c] = (dp3[r + 1][c - 1] + 1) * (d2[r][c] - '0');
            dp4[r][c] = (dp4[r + 1][c + 1] + 1) * (d2[r][c] - '0');
        }
    }
    for(int r = 1; r <= n; r++) {
        for(int c = 1; c <= m; c++) {
            if(d2[r][c] == '0') continue;
            int maxd = min(min(dp1[r - 1][c - 1], dp4[r + 1][c + 1]), min(dp2[r - 1][c + 1], dp3[r + 1][c - 1])) * 2 + 1;
            ans = max(ans, maxd);
        }
    }
    cout << ans;

    return 0;
}
