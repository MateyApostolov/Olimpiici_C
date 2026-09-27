#include <bits/stdc++.h>
using namespace std;

long long xorsum(long long n) {
    int mod = n % 4;
    if(mod == 0) return n;
    if(mod == 1) return 1;
    if(mod == 2) return n + 1;
    return 0;
}

int main () {
    long long l, r, res = 0;
    cin >> l >> r;
    if((r - l) % 2 == 0) {
        cout << 0;
        return 0;
    }
    cout << xorsum(r) - xorsum(l - 1);
    return 0;
    for(int i = 0; i < 60; i++) {
        long long hr = r, hl = l - 1;
        bool t = true;
        for(int x = 0; x <= 3; x++) {
            if(l - x < 0) {
                t = false;
                continue;
            }
            bool bitr = ((1LL << i) & (hr - x));
            bool bitl = ((1LL << i) & (hl - x));
            if(bitl != bitr) t = false;
        }
        if(!t) res = (res | (1 << i));
    }
    cout << res;
    return 0;
}

/*
0000 0
0001 1
0010 2
0011 3
0100 4
0101 5*
0110 6
0111 7
1000 8
1001 9
1010 10*
1011 11
1100 12
1101 13
1110 14
1111 15
*/









