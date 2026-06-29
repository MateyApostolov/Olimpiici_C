#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, nc, sum = 0, ans  = 0;
    cin >> n;
    map <long long, long long> mp;
    mp[0] = 1;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        if(i % 2 == 0) sum += nc;
        else sum -= nc;
        mp[sum]++;
    }
    for(auto [num, cnt] : mp) ans += (cnt * (cnt - 1)) / 2;
    cout << ans;
    return 0;
}

