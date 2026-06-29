#include <bits/stdc++.h>
using namespace std;

const int maxn = 2 * 1e5 + 1;
vector <int> gr[maxn];
bool vis[maxn];
int brv;

void dfs (int x) {
    brv++;
    vis[x] = true;
    for(auto u : gr[x]) {
        if(vis[u]) continue;
        dfs(u);
    }
}

int main () {
    int n, m, a, b, brr1 = 0, brr2 = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    for(int i = 1; i <= n; i++) {
        if(gr[i].size() == 1) brr1++;
        if(gr[i].size() == 2) brr2++;
    }
    if(!(brr1 == 2 && brr2 == n - 2)) {
        cout << "No";
        return 0;
    }
    dfs(1);
    if(brv == n) cout << "Yes";
    else cout << "No";

    return 0;
}
