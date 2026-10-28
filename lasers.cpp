#include <bits/stdc++.h>
using namespace std;

vector<array<int, 3>> event;
vector<int> ans;

void check() {
    sort(event.begin(), event.end());
    int stt = INT_MIN;
    for(auto [x, t, idx] : event) {
        if(t == 1) {
            stt = x;
            continue;
        }
        if(stt != INT_MIN) ans[idx] = min(ans[idx], x - stt);
    }
    reverse(event.begin(), event.end());
    stt = INT_MAX;
    for(auto [x, t, idx] : event) {
        if(t == 1) {
            stt = x;
            continue;
        }
        if(stt != INT_MAX) ans[idx] = min(ans[idx], stt - x);
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q, sum = 0, s;
    cin >> n >> m;
    pair<int, int> lsr[n], pts[m];
    map<int, int> cnt_pts, pref_cnt;
    ans.resize(m, INT_MAX);
    for(int i = 0; i < n; i++) cin >> lsr[i].first >> lsr[i].second;
    for(int i = 0; i < m; i++) cin >> pts[i].first >> pts[i].second;

    for(int i = 0; i < n; i++) event.push_back({lsr[i].first, 1, i});
    for(int i = 0; i < m; i++) event.push_back({pts[i].first, 2, i});
    check();
    event.clear();

    for(int i = 0; i < n; i++) event.push_back({lsr[i].second, 1, i});
    for(int i = 0; i < m; i++) event.push_back({pts[i].second, 2, i});
    check();

    for(auto x : ans) cnt_pts[x]++;
    for(auto x : cnt_pts) {
        sum += x.second;
        pref_cnt[x.first] = sum;
    }
    cin >> q;
    for(int i = 0; i < q; i++) {
        cin >> s;
        s /= 2;
        auto it = pref_cnt.upper_bound(s);
        it--;
        auto [k, value] = *it;
        cout << value << ' ';
    }
    return 0;
}
