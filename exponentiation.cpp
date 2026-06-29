#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int fexp (int num, int pow) {
    if(pow == 0) return 1;
    if(pow & 1) return (1LL * fexp(num, pow - 1) * num) % mod;
    int log2 = fexp(num, pow / 2) % mod;
    return (1LL * log2 * log2) % mod;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, a, b;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << fexp(a, b) << '\n';
    }

    return 0;
}
