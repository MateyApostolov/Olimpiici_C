#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, a1 = 1, a2 = 1, st[500] = {};
    cin >> n;
    map<pair<int, int>, int> mp;
    for(int i = 3; true; i++) {
        int a3 = (a1 + a2) % 100;
        if(mp[{a1, a2}] != 0) break;
        mp[{a1, a2}] = a3;
        st[i] = a3;
        a1 = a2;
        a2 = a3;
    }
    int ans = st[n % mp.size()];
    if(ans < 10) cout << 0;
    cout << ans;
    return 0;
}
