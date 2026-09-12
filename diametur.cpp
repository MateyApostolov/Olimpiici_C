#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
vector<int> tree[maxn];
int n, ans;
pair<int, int> dp[maxn], mp[maxn];

void dfs(int u, int parr) {
    if(dp[u].first < dp[parr].first + 1) {
        dp[u].second = dp[u].first + 1;
        dp[u].first = dp[parr].first + 1;
    } else if(dp[u].second < dp[parr].first + 1){
        dp[u].second = dp[parr].first + 1;
    } else if(dp[u].second < dp[parr].second + 1) {
        dp[u].second = dp[parr].second + 1;
    }
    for(auto v : tree[u]) {
        if(v == parr) continue;
        dfs(v, u);
    }
}

void undo(int u, int parr) {
    dp[u].first = mp[u].first;
    dp[u].second = mp[u].second;
    dp[parr].first = mp[parr].first;
    dp[parr].second = mp[parr].second;
}

void rerooting(int u, int parr, int res) {
    mp[u] = {dp[u].first, dp[u].second};
    ans = max(ans, res);
    for(auto v : tree[u]) {
        if(v == parr) continue;
        int v1 = -1, v2 = -1;
        if(dp[u].first != dp[v].first - 1) dp[v].first = dp[u].first + 1;
        if(dp[u].second != dp[v].second - 1) dp[v].second = dp[u].second + 1;
        int hres = dp[v].first + dp[v].second;
        rerooting(v, u, hres);
    }
    undo(u, parr);
}


int main () {
    int u, v;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1, 0);
    rerooting(1, 0, 0);
    cout << ans;

    return 0;
}
