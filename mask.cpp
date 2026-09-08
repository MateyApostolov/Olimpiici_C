#include <bits/stdc++.h>
using namespace std;

const int maxn = 20;
const int maxc = 2e6 + 1;
const long long INF = 1e18;
long long n, mm[maxn][maxc];
bool vis[maxn][maxc];
int dist[maxn+1][maxn+1];

long long rec(long long x, long long mask) {
    if(mask == ((1 << n) - 1)) return dist[x][0];
    if(vis[x][mask]) return mm[x][mask];
    long long res = INF;
    for(int i = 0; i < n; i++) {
        if (i==x) continue;
        if(mask & (1 << i)) continue;
        res = min(res, rec(i, (mask | (1 << i))) + dist[x][i]);
    }
    vis[x][mask] = true;
    return mm[x][mask] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long d;
    cin >> n;
    for(int u = 0; u < n; u++) {
        for(int v = 0; v < n; v++) {
            cin >> d;
            dist[u][v]=d;
        }
    }
    cout << rec(0, 0);
    return 0;
}
