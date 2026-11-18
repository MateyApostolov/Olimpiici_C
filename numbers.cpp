#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, cnt = 0, d5, d4, d3, d2, d1;
    cin >> n;
    d5 = n / 10000;
    d4 = n / 1000 % 10;
    d3 = n / 100 % 10;
    d2 = n / 10 % 10;
    d1 = n % 10;
    if(d5 + d3 != d4 || d1 + d3 != d2) {
        cout << 0;
        return 0;
    }
    for(int i = 10000; i <= 99999; i++) {
        d5 = i / 10000;
        d4 = i / 1000 % 10;
        d3 = i / 100 % 10;
        d2 = i / 10 % 10;
        d1 = i % 10;
        if(d5 + d3 == d4 && d1 + d3 == d2) cnt++;
        if(i == n) break;
    }
    cout << cnt;
    return 0;
}

