#include <bits/stdc++.h>
using namespace std;

const long long INF = 4e14;
long long t, n, a, b;

bool ok(long long x) {
    long long leftn = n;
    long long go_to_pile = 0;
    while(true) {
        go_to_pile += a;
        long long time_left = x - go_to_pile;
        if(time_left < 0) return false;
        long long cnt_pile = time_left / b + 1;
        long long eqtime = time_left % b;
        leftn -= (eqtime / a) * cnt_pile;
        go_to_pile += (eqtime / a) * (a - 1);
        if(leftn <= 0) return true;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> a >> b;
        long long l = 0, r = INF;
        while(l <= r) {
            long long mid = (l + r) / 2;
            if(ok(mid)) r = mid - 1;
            else l = mid + 1;
        }
        cout << l << '\n';
    }

    return 0;
}
