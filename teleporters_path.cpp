#include <bits/stdc++.h>
using namespace std;

vector<int> seq;

struct edg{
    int u, v;
    edg() : u(0), v(0) {}
    edg(int u, int v) : u(u), v(v) {}
    int other(int x) {
        return x == u ? v : u;
    }
};

void euler(int u, vector<edg> & edges, vector<vector<int>> & adj_edges) {
    while(!adj_edges[u].empty()) {
        int eu_idx = adj_edges[u].back();
        adj_edges[u].pop_back();
        int v = edges[eu_idx].other(u);
        euler(v, edges, adj_edges);
    }
    seq.push_back(u);
}

int main () {
    int n, m, u, v;
    cin >> n >> m;
    vector<edg> edges(m);
    vector<vector<int>> adj_edges(n);
    vector<int> inedg(n, 0), outedg(n, 0);
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        inedg[v]++;
        outedg[u]++;
        edges[i] = edg(u, v);
        adj_edges[u].push_back(i);
    }
    if(outedg[0] - 1 != inedg[0]) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    if(inedg[n - 1] - 1 != outedg[n - 1]) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for(int i = 1; i < n - 1; i++) {
        if(outedg[i] != inedg[i]) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    euler(0, edges, adj_edges);
    if(seq.size() - 1 != m) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    reverse(seq.begin(), seq.end());
    for(auto x : seq) {
        cout << x + 1 << ' ';
    }
    return 0;
}

