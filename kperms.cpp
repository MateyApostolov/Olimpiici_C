#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, k, ans = 0;
    cin >> n >> k;
    vector<int> perm;
    for(int i = 1; i <= n; i++) perm.push_back(i);
    while(next_permutation(perm.begin(), perm.end())) {
        bool t = true;
        int prev = perm[0];
        for(auto x : perm) {
            if(abs(x - prev) > k) t = false;
            prev = x;
        }
        if(t) ans++;
    }
    cout << ans + 1;
    return 0;
}
