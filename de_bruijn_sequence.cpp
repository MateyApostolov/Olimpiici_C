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
    int n, u, v;
    cin >> n;
    if(n == 1) {
        cout << "01";
        return 0;
    }
    vector<edg> edges(1 << n);
    vector<vector<int>> adj_edges(1 << (n - 1));
    for(int mask = 0; mask < (1 << n); mask++) {
        int pref = (mask >> 1);
        int suff = (mask & ((1 << (n - 1)) - 1));
        edges[mask] = edg(pref, suff);
        adj_edges[pref].push_back(mask);
    }
    euler(0, edges, adj_edges);
    for(int i = 0; i < seq.size(); i++) {
        cout << seq[i];
    }
    return 0;
}

