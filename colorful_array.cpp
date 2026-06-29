#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * 10e5 + 1;
int n, q, l, r, c;
int col[maxn], par[maxn], sz[maxn];

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
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 0; i < q; i++) {
        cin >> l >> r >> c;

    }

    return 0;
}
