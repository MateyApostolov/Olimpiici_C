#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, ans = INT_MAX;
    cin >> n;
    int a[n], b[n];
    bool t = true;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if(a[i] != b[i]) t = false;
    }
    if(t) {
        sort(a, a + n);
        cout << a[n - 1] - a[n - 2];
        return 0;
    }
    for(int i = 1; i <= (1 << n); i++) {
        int amax = 0, bmax = 0;
        for(int x = 0; x < n; x++) {
            if(((i >> x) & 1)) amax = max(amax, a[x]);
            else bmax = max(bmax, b[x]);
        }
        ans = min(ans, abs(amax - bmax));
    }
    cout << ans;
    return 0;
}
/*5
20 20
16 16
32 32
100 100
200 200*/
