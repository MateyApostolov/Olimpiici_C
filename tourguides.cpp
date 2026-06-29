#include <bits/stdc++.h>
using namespace std;


int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, x, y, t, k, q, ht;
    cin >> n >> m;
    vector <pair<int, int>> graph[n + 1];
    for(int i = 0; i < m; i++) {
        cin >> x >> y >> t;
        graph[x].push_back({y, t});
        graph[y].push_back({x, t});
    }
    cin >> k;
    int dist[n + 1];
    for(int i = 0; i <= n; i++) dist[i] = INT_MAX;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> dk;
    for(int i = 0; i < k; i++) {
        cin >> ht;
        dist[ht] = 0;
        dk.push({0, ht});
    }
    while(!dk.empty()) {
        int x = dk.top().second, d = dk.top().first;
        dk.pop();
        for(auto y : graph[x]) {
            int hd = y.second + d, hp = y.first;
            if(dist[hp] > hd) {
                dist[hp] = hd;
                dk.push({hd, hp});
            }
        }
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> ht;
        cout << dist[ht] << '\n';
    }
    return 0;
}
