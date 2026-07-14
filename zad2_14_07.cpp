#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
bool vis_stp[maxn], vis_line[maxn];

int main () {
    int n, k, kl, kc, s, f;
    cin >> n >> k;
    vector<int> stp[n + 1], line[k + 1];
    for(int i = 0; i < k; i++) {
        cin >> kl;
        for(int x = 0; x < kl; x++) {
            cin >> kc;
            line[i].push_back(kc);
            stp[kc].push_back(i);
        }
    }
    cin >> s >> f;
    queue <pair<int, int>> pqu;
    pqu.push({s, 0});
    vis_stp[s] = true;
    while(!pqu.empty()) {
        int u = pqu.front().first, dist = pqu.front().second;
        pqu.pop();
        if(u == f) {
            cout << dist;
            return 0;
        }
        for(auto v : stp[u]) {
            if(vis_line[v]) continue;
            vis_line[v] = true;
            for(auto sth : line[v]) {
                if(vis_stp[sth]) continue;
                vis_stp[sth] = true;
                pqu.push({sth, dist + 1});
            }
        }
    }
    cout << -1;
    return 0;
}
