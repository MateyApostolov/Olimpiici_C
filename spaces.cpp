#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, ans = 0, pr;
    cin >> n;
    pair<int, int> spc[n];
    for(int i = 0; i < n; i++) {
        cin >> spc[i].second >> spc[i].first;
    }
    sort(spc, spc + n);
    ans++;
    pr = spc[0].first;
    for(int i = 1; i < n; i++) {
        if(pr > spc[i].second) continue;
        ans++;
        pr = spc[i].first;
    }
    cout << ans;
    return 0;
}
