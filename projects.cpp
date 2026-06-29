#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    pair<pair<int, bool>, int> pg[2 * n];
    for(int i = 0; i < 2 * n; i++) {
        cin >> pg[i].first.first;
        pg[i].first.second = i % 2;
        pg[i].second = i / 2;
    }
    sort(pg, pg + 2 * n);
    int brb = 0, bre = 0, ans[n];
    int st[n];
    for(int i = 0; i < 2 * n; i++) {
        int idx = pg[i].second;
        if(pg[i].first.second == 0) {
            st[idx] = bre;
            brb++;
        } else {
            ans[idx] = brb - st[idx] - 1;
            bre++;
        }
    }
    for(int i = 0; i < n; i++) cout << ans[i] << ' ';
    return 0;
}
