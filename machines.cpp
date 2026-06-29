#include <bits/stdc++.h>
using namespace std;

const int maxn = 20001;
int vis[maxn];
bool ans;
vector <int> graph[maxn];

void dfs(int x) {
    vis[x] = 1;
    for(auto y : graph[x]) {
        if(vis[y] == 1) {
            ans = true;
            return;
        }
        if(vis[y] == 0) dfs(y);
    }
    vis[x] = 2;
    return;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k;
    cin >> k;
    vector <int> ksp;
    for(int i = 0; i < k; i++) {
        int n, a, b;
        cin >> n >> a;
        ksp.push_back(a);
        for(int j = 1; j < n; j++) {
            cin >> b;
            graph[a].push_back(b);
            a = b;
        }
    }
    for(int i = 0; i < ksp.size(); i++) {
        if(vis[ksp[i]] == 0) {
            dfs(ksp[i]);
        }
    }
    cout << !ans;
    return 0;
}
