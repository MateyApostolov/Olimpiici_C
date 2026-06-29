#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * 1e5 + 1;
int pw[maxn];
bool vis[maxn];
vector <int> graph[maxn];

int main () {
    int n, m, k, a, b, p, h;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    priority_queue <pair<int, int>> qu;
    vector <int> ans;
    for(int i = 0; i < k; i++) {
        cin >> p >> h;
        pw[p] = h;
        qu.push({h, p});
    }
    while(!qu.empty()) {
        int px = qu.top().second;
        qu.pop();
        if(vis[px]) continue;
        vis[px] = true;
        for(auto y : graph[px]) {
            if(vis[y]) continue;
            if(pw[px] - 1 >= pw[y] && pw[px] - 1 >= 0) {
                pw[y] = pw[px] - 1;
                qu.push({pw[y], y});
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        if(vis[i]) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}
