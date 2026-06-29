#include <bits/stdc++.h>
using namespace std;


const int maxl2 = 18;
const int maxn = 2e5 + 1;
int T, n, q, pr, jump[maxl2][maxn], in_t[maxn], out_t[maxn];
vector <int> nbs[maxn];


void dfs(int u, int par) {
    in_t[u] = ++T;
    jump[0][u] = par;
    for(auto x : nbs[u]) {
        dfs(x, u);
    }
    for(int l = 1; l < maxl2; l++) {
        if(jump[l - 1][u] == -1) break;
        jump[l][u] = jump[l - 1][jump[l - 1][u]];
    }
    out_t[u] = T;
    return;
}

bool is_anc(int u, int v) {
    return (in_t[u] <= in_t[v]) && (out_t[v] <= out_t[u]);
}

int get_lca(int u, int v) {
    if(is_anc(u, v)) return u;
    if(is_anc(v, u)) return v;
    for(int i = maxl2 - 1; i >= 0; i--) {
        if(jump[i][u] != -1 && !(is_anc(jump[i][u], v))) u = jump[i][u];
    }
    return jump[0][u];
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for(int i = 1; i < n; i++) {
        cin >> pr;
        pr--;
        nbs[pr].push_back(i);
    }
    for(int i = 0; i < maxl2; i++) jump[i][0] = -1;
    dfs(0, -1);
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << get_lca(a, b) << '\n';
    }

    return 0;
}
