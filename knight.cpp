#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 1;
bool vis[maxn][maxn];
pair<int, int> w[8] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int main () {
    int n, m, i, j, ans = 1;
    cin >> n >> m >> i >> j;
    vis[i][j] = true;
    while(true) {
        bool t = true;
        for(int x = 0; x < 8; x++) {
            int hi = i + w[x].first;
            int hj = j + w[x].second;
            if(hi < 1 || hj < 1 || hi > n || hj > m) continue;
            if(vis[hi][hj]) continue;
            i = hi;
            j = hj;
            vis[hi][hj] = true;
            t = false;
            ans++;
            break;
        }
        if(t) break;
    }
    cout << ans;
    return 0;
}
