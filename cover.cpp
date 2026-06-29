#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, l, r, hm = 0, hb = 0, ans = 0, ansm = 0;
    cin >> n;
    pair<int, int> nc[n * 2];
    for(int i = 0; i < n; i++) {
        cin >> l >> r;
        nc[2 * i] = {l, 1};
        nc[2 * i + 1] = {r, 0};
    }
    sort(nc, nc + n * 2);
    for(int i = 0; i < 2 * n; i++) {
        if(nc[i].second == 1) {
            hm++;
            hb = nc[i].first;
        } else {
            if(ans < hm) {
                ans = hm;
                ansm = nc[i].first - hb;
            }
            if(nc[i].first - hb == ansm) ansm += nc[i].first - hb;
            hm--;
        }

    }
    cout << ans << '\n' << ansm;
    return 0;
}
