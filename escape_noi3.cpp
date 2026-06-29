#include <bits/stdc++.h>
#define LL long long
using namespace std;

const LL INF = LLONG_MAX;
const int maxn = 2e5 + 1;
vector <pair<LL, pair<LL, LL>>> graph[maxn];
LL minp[maxn], minw[maxn];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    LL n, m, a, b, p, w;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> p >> w;
        graph[a].push_back({b, {p, w}});
        graph[b].push_back({a, {p, w}});
    }
    priority_queue <pair<LL, LL>, vector<pair<LL, LL>>, greater<pair<LL, LL>>> pqu;
    pqu.push({0, 1});
    minp[1] = 0;
    for(int i = 0; i <= n; i++) minp[i] = INF;
    while(!pqu.empty()) {
        LL pu = pqu.top().first, u = pqu.top().second;
        pqu.pop();
        if(minp[u] < pu) continue;
        for(auto[v, pv] : graph[u]) {
            LL news = max(pu, pv.first);
            if(minp[v] > news) {
                pqu.push({news, v});
                minp[v] = news;
            }
        }
    }
    pqu.push({0, 1});
    minw[1] = 0;
    for(int i = 0; i <= n; i++) minw[i] = INF;
    while(!pqu.empty()) {
        LL pu = pqu.top().first, u = pqu.top().second;
        pqu.pop();
        if(minw[u] < pu) continue;
        for(auto v : graph[u]) {
            LL nextv = v.first, ndis = v.second.second + pu;
            if(v.second.first > minp[n]) continue;
            if(minw[nextv] > ndis) {
                pqu.push({ndis, nextv});
                minw[nextv] = ndis;
            }
        }
    }
    cout << minp[n] << ' '  << minw[n];
    return 0;
}
