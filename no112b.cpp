#include <bits/stdc++.h>
using namespace std;

const int maxn = 10e3 + 1;
int par[maxn], sz[maxn];

int findp(int u) {
    if(par[u] == u) return u;
    return par[u] = findp(par[u]);
}

void uni(int u, int v) {
    u = findp(u);
    v = findp(v);
    if(u == v) return;
    if(sz[u] < sz[v]) swap(u, v);
    par[v] = u;
    sz[u] += sz[v];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q, u, v, t;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        uni(u, v);
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> t >> u >> v;
        if(t == 1) {
            if(findp(u) == findp(v)) cout << 1;
            else cout << 0;
        } else uni(u, v);
    }

    return 0;
}

