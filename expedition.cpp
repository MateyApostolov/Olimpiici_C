#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 1;
vector<pair<long long, long long>> plat(maxn);

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, c, event, ans, res, mins;
    cin >> n >> m >> c;
    for(int i = 0; i < n; i++) {
        cin >> plat[i].first >> plat[i].second;
    }
    int res[n];
    for(int i = 0; i < m; i++) {
        cin >> event;
        mins = -1;
        for(int i = 0; i < n; i++) {
            res[i] = (plat[i].first - event) * c + plan[i].second;
            if(res > mins && )
        }
        sort(res, res + n);
        for(int i = 0; i < n; i++) {

        }
    }
    cout << ans;
    return 0;
}
