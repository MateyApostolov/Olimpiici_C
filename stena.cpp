#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
vector <int> gr[maxn];
bool vis[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, a, b, p, ans = 1;
    cin >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> a >> b;
        vis[b] = true;
        gr[a].push_back(b);
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            p = i;
            break;
        }
    }
    while(!gr[p].empty()) {
        p = gr[p][0];
        ans++;
    }
    cout << ans;
    return 0;
}
