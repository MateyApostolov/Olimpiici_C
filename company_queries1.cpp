#include <bits/stdc++.h>
using namespace std;


const int maxl2 = 18;
const int maxn = 2e5 + 1;
int n, q, pr, jump[maxl2][maxn];
vector <int> nbs[maxn];

void dfs(int u, int par) {
    jump[0][u] = par;
    for(int l = 1; l < maxl2; l++) {
        if(jump[l - 1][u] == -2) break;
        jump[l][u] = jump[l - 1][jump[l - 1][u]];
    }
    for(auto x : nbs[u]) {
        dfs(x, u);
    }
    return;
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
    for(int i = 0; i < maxl2; i++) jump[i][0] = -2;
    dfs(0, -2);
    for(int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        x--;
        for(int i = maxl2 - 1; i >= 0; i--) {
            if(x != -2 && ((k >> i) & 1)) {
                x = jump[i][x];
            }
        }
        cout << x + 1 << '\n';
    }

    return 0;
}
