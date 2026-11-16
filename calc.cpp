#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    while(cin >> s) {
        int h = 0, c = 0, sum = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            c += (1 << h) * (s[i] - '0');
            h++;
            if(h == 3) {
                h = 0;
                sum += c;
                c = 0;
            }
        }
        sum += c;
        if(sum % 7 == 0) cout << "YES\n";
        else cout << 7 - sum % 7 << '\n';
    }

    return 0;
}
