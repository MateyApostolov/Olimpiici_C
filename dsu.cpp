#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
int par[maxn], sz[maxn];

int findp (int x) {
    if(par[x] == x) return x;
    return par[x] = findp(par[x]);
}

void uni (int x, int y) {
    x = findp(x);
    y = findp(y);
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x, y);
    par[y] = x;
    sz[x] += sz[y];
}

int main () {
    int n, q, t, a, b;
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        par[i] = i;
        sz[i] = 1;
    }
    for(int i = 0; i < q; i++) {
        cin >> t >> a >> b;
        if(t == 1) {
            uni(a, b);
        }
        if(t == 2) {
            if(findp(a) == findp(b)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
