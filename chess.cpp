#include <bits/stdc++.h>
using namespace std;

pair<int, int> w[8] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1}};

int main () {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        bool vis[8][8];
        for(int x = 0; x < 8; x++) {
            for(int y = 0; y < 8; y++) {
                vis[x][y] = false;
            }
        }
        int x1 = s1[0] - 'a', y1 = s1[1] - '0' - 1, x2 = s2[0] - 'a', y2 = s2[1] - '0' - 1;
        queue <pair<pair<int, int>, int>> qu;
        qu.push({{x1, y1}, 0});
        vis[x1][y1] = true;
        while(!qu.empty()) {
            int x = qu.front().first.first, y = qu.front().first.second, sec = qu.front().second;
            if(x == x2 && y == y2) {
                if(sec % 2 != 0) cout << -1 << '\n';
                else cout << sec / 2 << '\n';
                break;
            }
            qu.pop();
            for(int p = 0; p < 8; p++) {
                int hi = x + w[p].first;
                int hj = y + w[p].second;
                if(hi < 0 || hj < 0 || hi >= 8 || hj >= 8) continue;
                if(vis[hi][hj]) continue;
                vis[hi][hj] = true;
                qu.push({{hi, hj}, sec + 1});
            }
        }
    }

    return 0;
}
