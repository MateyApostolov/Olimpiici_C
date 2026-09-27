#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n, c, res = 0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c;
        res = (res ^ c);
    }
    cout << res;
    return 0;
}
