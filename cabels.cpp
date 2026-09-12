#include <bits/stdc++.h>
using  namespace std;

int main () {
    long long n, c, ans = 0;
    cin >> n;
    priority_queue<long long, vector <long long>, greater<long long>> pqu;
    for(int i = 0; i < n; i++) {
        cin >> c;
        pqu.push(c);
    }
    while(!pqu.empty()) {
        long long c1 = pqu.top();
        pqu.pop();
        if(pqu.empty()) break;
        long long c2 = pqu.top();
        pqu.pop();
        ans += c1 + c2;
        pqu.push(c1 + c2);
    }
    cout << ans;
    return 0;
}
