#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7 + 1;
int nmd[maxn];
bool vis[maxn];
unordered_map <int, unordered_map<int, int>> graph;

void eratosten () {
    for(long long d = 2; d < maxn; d++) {
        if(nmd[d] != 0) continue;
        nmd[d] = d;
        for(long long h = d * d; h < maxn; h += d) {
            if(nmd[h] != 0) continue;
            nmd[h] = d;
        }
    }
    return;
}

void add_to_graph(int num) {
    int pr = 0, div;
    while(num > 1) {
        div = nmd[num];
        num /= div;
        if(div == pr) continue;
        if(pr == 0) graph[div][div] = 1;
        else {
            graph[div][pr]++;
            graph[pr][div]++;
        }
        pr = div;
    }
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    eratosten();
    int n, nc, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        if(nc == 1) ans++;
        else add_to_graph(nc);
    }
    for(auto d : graph) {
        if(vis[d.first]) continue;
        vis[d.first] = true;
        ans++;
        queue <int> bfs;
        bfs.push(d.first);
        while(!bfs.empty()) {
            int x = bfs.front();
            bfs.pop();
            for(auto y : graph[x]) {
                if(vis[y.first]) continue;
                vis[y.first] = true;
                bfs.push(y.first);
            }
        }
    }
    cout << ans;
    return 0;
}
