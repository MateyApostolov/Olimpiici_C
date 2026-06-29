#include <bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector <pair<int, int>> tl(n);
    for(auto &[r, l] : tl) {
        cin >> l >> r;
    }
    sort(tl.begin(), tl.end());
    int hr = 0, ans = 0;
    for(auto &[r, l] : tl) {
        if(hr < r) {
            ans++;
            hr = r;
        }
    }
    cout << ans;
    return 0;
}
