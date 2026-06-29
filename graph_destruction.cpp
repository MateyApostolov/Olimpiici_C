#include <bits/stdc++.h>
using namespace std;

const int maxn = 10e3 + 1;
int par[maxn], ksz[maxn];

int find_p(int u) {
    if(par[u] == u) return u;
    return par[u] = find_p(par[u]);
}

void union_(int u, int v) {
    u = find_p(u);
    v = find_p(v);
    if(u == v) return;
    par[v] = u;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q, u, v, t;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) par[i] = i;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        union_(u, v);
    }

    return 0;
}


