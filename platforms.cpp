#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 2;
int d2[maxn][maxn];
bool vis[maxn][maxn];
pair<int, int> p[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

int bfs(int x, int y) {
    vis[x][y] = true;
    int res = 0;
    for(int pidx = 0; pidx < 4; pidx++) {
        int px = x + p[pidx].first;
        int py = y + p[pidx].second;
        if(d2[px][py] == -1 || vis[px][py] || d2[px][py] != d2[x][y]) continue;
        res += bfs(px, py);
    }
    return res + 1;
}

int main () {
    int n, m, ans;
    cin >> n >> m;
    ans = n * m;
    for(int i = 0; i <= n + 1; i++) {
        for(int j = 0; j <= m + 1; j++) {
            if(i == 0 || i == n + 1 || j == 0 || j == m + 1) {
                d2[i][j] = -1;
                continue;
            }
            cin >> d2[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int res = bfs(i, j);
            ans = ans - res + 1;
        }
    }
    cout << ans;
    return 0;
}
