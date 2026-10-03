#include <bits/stdc++.h>
using namespace std;

const int maxb = 31;
int trie[2][maxb], cnt[maxb], t = 1, ans;

void upd_trie(int mask) {
    int curr = 1;
    for(int i = maxb - 1; i >= 0; i--) {
        int kid = trie[((mask >> i) & 1)][curr];
        if(!kid) {
            trie[((mask >> i) & 1)][curr] = ++t;
            kid = t;
        }
        cnt[curr]++;
        curr = kid;
    }
    cnt[curr]++;
}

void del_trie(int mask) {
    int curr = 1;
    for(int i = maxb - 1; i >= 0; i--) {
        int kid = trie[((mask >> i) & 1)][curr];
        cnt[curr]--;
        curr = kid;
    }
    cnt[curr]--;
}

void find_xor(int x) {
    int curr = 1;
    for(int i = maxb - 1; i >= 0; i--) {
        if(!cnt[curr]) continue;
        int kid;
        if(((x >> i) & 1)) {
            kid = trie[0][curr];
            if(!cnt[kid]) ans ^= (1 >> i);
            else ans ^= (0 >> i);
            find_xor(kid);
        } else {
            kid = trie[1][curr];
            if(!cnt[kid]) ans ^= (0 >> i);
            else ans ^= (1 >> i);
            find_xor(kid);
        }
        curr = kid;
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int q, num;
    cin >> q;
    char c;
    for(int i = 0; i < q; i++) {
        cin >> c >> num;
        if(c == '+') {
            upd_trie(num);
        } else if(c == '-') {
            del_trie(num);
        } else {
            ans = 0;
            find_xor(num);
            cout << ans << '\n';
        }
    }
    return 0;
}
