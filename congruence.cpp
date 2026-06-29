#include <bits/stdc++.h>
using namespace std;

const int maxs = 26;
bool sc[maxs];
int outmin[maxs], outmax[maxs];

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        sc[s[i] - 'A'] = true;
    }
    char hp = 'A';
    for(int i = 0; i < 26; i++) {
        if(!sc[i]) continue;
        outmin[i] = hp;
        hp++;
    }
    for(int i = 0; i < s.size(); i++) {
        cout << char(outmin[s[i] - 'A']);
    }
    cout << '\n';
    hp = 'Z';
    for(int i = 25; i >= 0; i--) {
        if(!sc[i]) continue;
        outmax[i] = hp;
        hp--;
    }
    for(int i = 0; i < s.size(); i++) {
        cout << char(outmax[s[i] - 'A']);
    }
    return 0;
}
