#include <bits/stdc++.h>
using namespace std;

const int d7 = 1e9 + 7;
const int maxn = 1e6 + 1;
long long fact[maxn];

long long bst(long long num, int step) {
    if(step == 0) return 1;
    if(step == 1) return num;
    if(step % 2 != 0) {
        return (bst(num, step - 1) * num) % d7;
    }
    long long c = bst(num, step / 2);
    return (c * c) % d7;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fact[0] = 1;
    for(int i = 1; i <= maxn; i++) fact[i] = (fact[i - 1] * i) % d7;
    long long t, n, k;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> k;
        cout << (((fact[n] * bst(fact[n - k], d7 - 2)) % d7) * bst(fact[k], d7 - 2)) % d7 << '\n';
    }

    return 0;
}
