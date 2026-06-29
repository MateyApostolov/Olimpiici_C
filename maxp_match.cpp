#include <bits/stdc++.h>
using namespace std;

int main () {
    long long n, sum1 = 0, sum2 = 0;
    cin >> n;
    pair<int, pair<int, int>> nc[2 * n];
    for(int i = 0; i < 2 * n; i++) {
        cin >> nc[i].second.first >> nc[i].second.second;
        if(nc[i].second.first > nc[i].second.second) swap(nc[i].second.first, nc[i].second.second);
        nc[i].first = nc[i].second.first + nc[i].second.second;
    }
    sort(nc, nc + 2 * n);
    for(int i = 0; i < n; i++) {
        sum1 += nc[i].second.first;
    }
    for(int i = n; i < 2 * n; i++) {
        sum2 += nc[i].second.second;
    }
    cout << sum2 - sum1;
    return 0;
}
