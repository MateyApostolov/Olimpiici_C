#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 1;
long long pref[maxn], c, ans;
map<int, long long> cnt;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    cnt[0]++;
    for(int i = 1; i <= n; i++) {
        cin >> c;
        pref[i] = (pref[i - 1] ^ c);
        cnt[pref[i]]++;
    }
    for(auto [x, br] : cnt) {
        ans += (br * (br - 1)) / 2;
    }
    cout << ans;
    return 0;
}
