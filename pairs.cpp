#include <bits/stdc++.h>
using namespace std;

const int maxn = pow(10, 6) + 1;
vector <long long> graph[maxn];
bool vis[maxn];
long long brs;

void dfs (int x) {
    for(auto y : graph[x]) {
        if(vis[y]) continue;
        vis[y] = true;
        dfs(y);
        brs++;
    }
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, m, a, b, ans;
    cin >> n >> m;
    ans = n * (n - 1) / 2;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        dfs(i);
        ans -= brs * (brs - 1) / 2;
        brs = 0;
    }
    cout << ans;
    return 0;
}
