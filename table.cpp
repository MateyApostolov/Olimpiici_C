#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 1;
long long fact[maxn], prec[maxn];

int n, mod;

long long bst(long long num, int step) {
    if(step == 0) return 1;
    if(step == 1) return num;
    if(step % 2 != 0) {
        return (bst(num, step - 1) * num) % mod;
    }
    long long c = bst(num, step / 2);
    return (c * c) % mod;
}

int main () {
    cin >> n >> mod;
    fact[0] = 1;
    for(int i = 1; i <= maxn; i++) fact[i] = (fact[i - 1] * i) % mod;
    n /= 2;
    for(int i = 1; i <= n; i++) {
        prec[n + 1] = bst(fact[n - 1], mod - 2);
        prec[n] = (prec[n + 1] * (n + 1)) % mod;
        prec[n - 1] = (prec[n] * n) % mod;
        long long ccur =
         for(int j = 1; j <= n; j++) {
            long long s1 = ((fact[2 * n] * prec[n]) % mod * prec[n]) % mod;
            long long s2 = ((fact[2 * n] * prec[n - 1]) % mod * prec[n + 1]) % mod;

        }
        long long s1 = ((fact[2 * n] * prec[n]) % mod * prec[n]) % mod;
        long long s2 = ((fact[2 * n] * prec[n - 1]) % mod * prec[n + 1]) % mod;
    }
    cout << (s1 - s2) % mod;
    return 0;
}
