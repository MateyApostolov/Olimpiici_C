#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
vector <pair<int, int>> graph[maxn];
bool vis[maxn];

int main () {
    int n, m, ans = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqu;
    pqu.push({0, 0});
    while(!pqu.empty()) {
        int ds = pqu.top().first, u = pqu.top().second;
        if(vis[u]) continue;
        vis[u] = true;
        ans += ds;
        pqu.pop();
        for(auto [x, hds] : graph[u]) {
            if(vis[x]) continue;
            pqu.push({hds, x});
        }
    }
    cout << ans;
    return 0;
}
