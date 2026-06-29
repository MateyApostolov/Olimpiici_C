#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int maxn = 301;
int n, m, k;
int mm[maxn][maxn], mc[maxn][maxn];
bool vis[maxn][maxn];

int Pasc(int j, int i) {
    if(mc[j][i] != 0) return mc[j][i];
    if(j == i || j == 1 || i == 0) return mc[j][i] = 1;
    return mc[j][i] = (Pasc(j - 1, i - 1) + Pasc(j - 1, i)) % mod;
}

int brs (int rest, int dig) {
    if(rest == 0) return 1;
    if(dig == m) return 0;
    if(vis[rest][dig]) return mm[rest][dig];
    vis[rest][dig] = true;
    int sl = min(rest, k);
    for(int i = 0; i <= sl; i++) mm[rest][dig] = (1LL * mm[rest][dig] + (1LL * brs(rest - i, dig + 1) * Pasc(rest, i)) % mod) % mod;
    return mm[rest][dig];
}

int main () {
    cin >> n >> m >> k;
    cout << brs(n, 0);

    return 0;
}
