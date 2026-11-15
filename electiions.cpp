#include <bits/stdc++.h>
using namespace std;

const int d7 = 1e9 + 7;
const int maxn = 5e5 + 1;
long long fact[maxn], pref[maxn];
map<int, int> cnt;

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
    for(int i = 0; i < n; i++) {
        cin >> c;
        cnt[c]++;
    }
    for(int i = n - 1; i >= 0; i--) prec[i] = (prec[i + 1] * (i + 1)) % d7;
    for(auto [c, br] : cnt) {
        int h, k = n - br;
        long long s1, s2;
        prec[n] = bst(fact[n], d7 - 2);
        for(int j = 1; j <= br; j++) {
            s1 = (fact[n - br] * bst(fact[n - br - j - 1], d7 - 2)) % d7;
            s2 = (s1 * bst(fact[j], d7 - 2)) % d7;
            pref[i] = (pref[i] + prec[n - br])
        }
        if(i <= n / 2 + (n % 2)){
            h = i - 1;
            s1 = (fact[n - 1] * bst(fact[n - h - 1], d7 - 2)) % d7;
            s2 = (s1 * bst(fact[h], d7 - 2)) % d7;
        } else {
            h = n - i;
            s1 = (fact[n - 1] * mm[fact[n - h - 1]]) % d7;
            s2 = (s1 * mm[fact[h]]) % d7;
        }
        long long s3 = (s2 * c) % d7;
        ans = (ans + s3) % d7;
    }
    cout << ans;
    return 0;
}

