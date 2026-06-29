#include <bits/stdc++.h>
using namespace std;

const int maxpr = 1e7 + 1;
int nmd[maxpr];
vector <int> prime;

void eratosten () {
    for(long long d = 2; d < maxpr; d++) {
        if(nmd[d] == 0) {
            nmd[d] = d;
            prime.push_back(nmd[d]);
            for(long long h = d * d; h < maxpr; h += d) {
                if(nmd[h] == 0) nmd[h] = d;
            }
        }
    }
    return;
}

long long find_nmd (long long num) {
    for(auto div : prime) {
        if(num % div == 0) return div;
        if(1LL * div * div > num) return num;
    }
    return num;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    eratosten();
    int n;
    cin >> n;
    long long nc, h;
    for(int i = 0; i < n; i++) {
        cin >> nc;
        unordered_map <long long, int> can;
        while(nc > 1) {
            if(nc < maxpr) h = nmd[nc];
            else h = find_nmd(nc);
            can[h]++;
            nc /= h;
        }
        long long ans = 1;
        for(auto x : can) {
            long long sum = 1, pwr = 1;
            for(int p = 1; p <= x.second; p++) {
                pwr *= x.first;
                sum += pwr;
            }
            ans *= sum;
        }
        cout << ans << '\n';
    }

    return 0;
}
