#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 1;
int ans[maxn];
vector <pair<int, int>> add[maxn];

int main () {
    int n, l, r;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> l >> r;
        add[l].push_back({r, i});
    }
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pqu;
    for(int i = 1; i <= n; i++) {
        for(auto x : add[i]) {
            pqu.push(x);
        }
        if(pqu.empty() || pqu.top().first < i) {
            cout << "NO";
            return 0;
        }
        ans[pqu.top().second] = i;
        pqu.pop();
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}

