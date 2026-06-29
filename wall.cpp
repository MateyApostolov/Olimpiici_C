#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, k, ans = 0;
    cin >> n >> k;
    pair <long long, long long> w[n];
    for(int i = 0; i < n; i++) {
        cin >> w[i].second >> w[i].first;
    }
    sort(w, w + n);
    reverse(w, w + n);
    priority_queue <long long> mod;
    for(int i = 0; i < n; i++) {
        if(k == 0) break;
        while(!mod.empty() && k > 0 && w[i].first <= mod.top()) {
            ans += mod.top();
            k--;
            mod.pop();
        }
        if(k < w[i].second / w[i].first) {
            ans += w[i].first * k;
            k = 0;
        } else {
            ans += w[i].second / w[i].first * w[i].first;
            k -= w[i].second / w[i].first;
            mod.push(w[i].second % w[i].first);
        }
    }
    while(!mod.empty() && k > 0) {
        k--;
        ans += mod.top();
        mod.pop();
    }
    cout << ans;
    return 0;
}
