#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
const int maxn = 2e3 + 500;

struct edg{
    int u, v, w;

};

int main () {
    int n, m;
    cin >> n >> m;
    vector<edg> edges(m);
    for(auto &[u, v, w] : edges) {
        cin >> u >> w >> w;
        u--;
        v--;
        adj[u].push_back({v, w});
    }


    return 0;
}

