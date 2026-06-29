#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * 1e4 + 1;
const int INF = 1e9;
vector <pair<int, int>> gr[maxn];
int dist[maxn];
bool vis[maxn];

int main () {
    int n, m, a, b, w, s;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        gr[a].push_back({b, w});
        gr[b].push_back({a, w});
    }
    ///for(int i = 1; i < n; i++) dist[i] = INF;
    priority_queue<pair<int, int>> prq;
    dist[0] = INF;
    prq.push({dist[0], 0});
    while(!prq.empty()) {
        auto [d, u] = prq.top();
        prq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [v, we] : gr[u]) {
            if(vis[v]) continue;
            if(dist[v] < min(dist[u], we)) {
                dist[v] = min(dist[u], we);
                prq.push({dist[v], v});
            }
        }
    }
    for(int i = 1; i < n; i++) {
        cout << dist[i] << ' ';
    }
    return 0;
}

