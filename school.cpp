#include <bits/stdc++.h>
using namespace std;

const int maxn = 3 * 1e5 + 1;
unsigned long long a[maxn], b[maxn];
unsigned long long n, m, l = 0, r = 1e9;

bool ok (unsigned long long num) {
    unsigned long long give = 0, take = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] * m < num) {
            take += (num - a[i] * m + b[i] - 1) / b[i];
        }
        if(a[i] * m >= num) {
            give += (a[i] * m - num) / a[i];
        }

    }
    if(give < take) return false;
    return true;
}

int main () {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) a[i] = max(a[i], b[i]);
    while(l <= r) {
        unsigned long long mid = l + (r - l + 1) / 2;
        if(ok(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << r;
    return 0;
}
