#include <bits/stdc++.h>
using namespace std;

const int maxn = 151;
const int maxv = 501;
const int INF = 1e9;
int n, m, s;

vector <array<int, 3>> grp[maxn];
double dis[maxn][maxv];
pair<int, int> par[maxn][maxv];
bool vis[maxn][maxv];

struct Node{
    double len;
    int vel, idx;
    Node(double len, int idx, int vel) : len(len), idx(idx), vel(vel) {}
    friend bool operator<(const Node& lhs, const Node& rhs) {
        return lhs.len > rhs.len;
    }
};

int main () {
    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) {
        int a, b, vel, len;
        cin >> a >> b >> vel >> len;
        grp[a].push_back({b, len, vel});
    }
    for(int i = 0; i < n; i++) {
        for(int v = 0; v <= 500; v++) {
            dis[i][v] = INF;
        }
    }
    priority_queue <Node> pqu;
    pqu.push(Node(0, 0, 70));
    dis[0][70] = 0;
    while(!pqu.empty()) {
        auto node = pqu.top();
        pqu.pop();
        int a = node.idx;
        int vel = node.vel;
        if(vis[a][vel]) continue;
        vis[a][vel] = true;
        for(auto [b, len, nvel] : grp[a]) {
            if(nvel == 0) nvel = vel;
            double t = dis[a][vel] + 1.0 * len / nvel;
            if(!vis[a][nvel] && t < dis[a][nvel]) {
                pqu.push(Node(t, b, nvel));
                dis[b][nvel] = t;
                par[b][nvel] = {b, vel};
            }
        }
    }
    int ver = s, grv = 1;
    for(int vel = 1; vel <= maxv; vel++) {
        if(dis[ver][grv] > dis[ver][vel]) grv = vel;
    }
    vector <int> ans;
    while(true) {
        ans.push_back(ver);
        auto [nver, ngrv] = par[ver][grv];
        if(ngrv == 0) break;
        ver = nver;
        grv = ngrv;
    }
    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
    return 0;
}
