#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, cnt = 0;
    cin >> n;
    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;
        bool t1 = false, t3 = false;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == '1') t1 = true;
            if(t1 && s[j] == '3') t3 = true;
        }
        if(t1 && t3) cnt++;
    }
    if(!cnt) cout << "No";
    else cout << cnt;
    return 0;
}
