#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 1;
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
    cin >> s;
    for(int i = 0; i < n; i++) dist[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> prq;
    dist[s] = 0;
    prq.push({dist[s], s});
    while(!prq.empty()) {
        auto [d, u] = prq.top();
        prq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [v, we] : gr[u]) {
            if(vis[v]) continue;
            if(dist[v] > dist[u] + we) {
                dist[v] = dist[u] + we;
                prq.push({dist[v], v});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << dist[i] << ' ';
    }
    return 0;
}
