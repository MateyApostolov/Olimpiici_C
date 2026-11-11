#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, int> devs, nod;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    long long h = 0, sum = 0, ans = 0;
    vector<int> nc(n);
    for(int i = 0; i < n; i++) {
        cin >> nc[i];
        sum += nc[i];
    }
    for(long long x = 1; x * x <= sum; x++) {
        if(sum % x == 0) {
            devs[x] = 0;
            devs[sum / x] = 0;
        }
    }
    for(int i = 0; i < n; i++) {
        h += nc[i];
        nod[__gcd(h, sum)]++;
    }
    for(auto &[dev, br] : devs) {
        for(auto [c, t] : nod) {
            if(c % dev == 0) {
                br += t;
            }
        }
    }
    for(auto [g, t] : devs) if(g * t == sum) ans++;
    cout << ans;
    return 0;
}
