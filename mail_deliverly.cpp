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

void euler(int u, vector<edg> & edges, vector<vector<int>> & adj_edges, vector<int> & note) {
    while(!adj_edges[u].empty()) {
        int eu_idx = adj_edges[u].back();
        adj_edges[u].pop_back();
        if(note[eu_idx]) continue;
        note[eu_idx] = true;
        int v = edges[eu_idx].other(u);
        euler(v, edges, adj_edges, note);
    }
    seq.push_back(u);
}

int main () {
    int n, m, u, v;
    cin >> n >> m;
    vector<edg> edges(m);
    vector<vector<int>> adj_edges(n);
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        edges[i] = edg(u, v);
        adj_edges[u].push_back(i);
        adj_edges[v].push_back(i);
    }
    for(int i = 0; i < n; i++) {
        if(adj_edges[i].size() % 2 == 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    vector<int> note(m, 0);
    euler(0, edges, adj_edges, note);
    if(seq.size() - 1 != m) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    for(auto x : seq) {
        cout << x + 1 << ' ';
    }
    return 0;
}

