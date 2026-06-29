#include <bits/stdc++.h>
using namespace std;

const int maxn = 5 * 1e5 + 1;
int nmp[maxn];
map <int, bool> primes;

void eratosten() {
    for(long long d = 2; d < maxn; d++) {
        if(nmp[d] != 0) continue;
        nmp[d] = d;
        for(long long h = d * d; h < maxn; h += d) {
            if(nmp[h] != 0) continue;
            nmp[h] = d;
        }
    }
    return;
}

void can(int num) {
    while(num > 1) {
        primes[nmp[num]] = true;
        num /= nmp[num];
    }
    return;
}

int main () {
    eratosten();
    int l, r;
    cin >> l >> r;
    for(int i = l; i <= r; i++) can(i);
    cout << primes.size();
    return 0;
}
