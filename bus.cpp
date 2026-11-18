#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, a, b, ans = 0;
    cin >> n >> a >> b;
    vector<array<int, 3>> mar(n);
    for(int i = 0; i < n; i++) {
        cin >> mar[i][0] >> mar[i][1] >> mar[i][2];
    }
    sort(mar.begin(), mar.end());
    bool t = false;
    for(int i = 0; i < mar.size(); i++) {
        if(b <= mar[i][0]) break;
        if(!t && mar[i][1] > a && mar[i][0] <= a) t = true;
        if(t) ans += mar[i][2];
    }
    cout << ans;
    return 0;
}


