#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * pow(10, 5) + 1;
vector <int> graph[3 * maxn];
int dist[3 * maxn];
bool vis[3 * maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, k, a, b, t, ans = INT_MAX;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> t;
        a--;
        b--;
        t--;
        for(int x = 0, y = t; y <= 2; x++, y++) {
            graph[x * n + a].push_back(y * n + b);
            graph[x * n + b].push_back(y * n + a);
        }
    }
    for(int i = 0; i < 3 * n; i++) dist[i] = INT_MAX;
    queue <int> qu;
    qu.push(0);
    dist[0] = 0;
    vis[0] = true;
    while(!qu.empty()) {
        auto u = qu.front();
        qu.pop();
        for(auto v : graph[u]) {
            if(vis[v]) continue;
            vis[v] = true;
            dist[v] = dist[u] + 1;
            qu.push(v);
        }
    }
    for(int ki = 0; ki <= k; ki++) {
        ans = min(ans, dist[ki * n + n - 1]);
    }
    if(ans == INT_MAX) cout << -1;
    else cout << ans;
    return 0;
}

