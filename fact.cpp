#include <bits/stdc++.h>
using namespace std;

const int maxc = 1e4 + 1;
bool ispr[maxc];
int ngpr[maxc];
map<int, int> prime;


void eratosten() {
    for(int d = 2; d < maxc; d++) {
        if(ispr[d]) continue;
        ngpr[d] = d;
        for(int h = d * d; h < maxc; h += d) {
            ispr[h] = true;
            ngpr[h] = d;
        }
    }
}

void can(int num) {
    while(num > 1) {
        prime[ngpr[num]]++;
        num /= ngpr[num];
    }
    return;
}

int main () {
    eratosten();
    int n, ans = 0;
    cin >> n;
    ngpr[1] = 1;
    for(int i = 2; i <= n; i++) {
        can(i);
    }
    for(auto [c, cnt] : prime) {
        ans += cnt;
    }
    cout << ans;
    return 0;
}
