#include <bits/stdc++.h>
using namespace std;

const int d7 = 1e9 + 7;
const int maxn = 5e5 + 1;
long long fact[maxn], prec[maxn];

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
    long long n, c, ans = 0;
    cin >> n;
    prec[n] = bst(fact[n], d7 - 2);
    for(int i = n - 1; i >= 0; i--) prec[i] = (prec[i + 1] * (i + 1)) % d7;
    for(int i = 1; i <= n; i++) {
        cin >> c;
        int h;
        long long s1, s2;
        if(i <= n / 2 + (n % 2)) h = i - 1;
        else h = n - i;
        s1 = (fact[n - 1] * prec[n - h - 1]) % d7;
        s2 = (s1 * prec[h]) % d7;
        long long s3 = (s2 * c) % d7;
        ans = (ans + s3) % d7;
    }
    cout << ans;
    return 0;
}
