#include <bits/stdc++.h>
using namespace std;

const int maxn = 8e6;
const int maxp = 4e6;
const int INF = 1e9;
vector <int> A, B;

void cnt_sort (vector <int> &nc) {
    bool cnt[maxn] = {};
    for(int num : nc) {
        cnt[num] = true;
    }
    nc.clear();
    for(int i = 0; i < maxn; i++) {
        if(cnt[i]) nc.push_back(i - maxp);
    }
}

int main () {
    int n, l, p, f, m, r, q, g, num = 0, idA = 0, idB;
    cin >> n >> l >> p >> f;
    cin >> m >> r >> q >> g;
    for(int i = 0; i < n; i++) {
        num = (num + l) % p;
        A.push_back(num);
    }
    for(int i = 0; i < m; i++) {
        num = (num + r) % q;
        B.push_back(num);
    }
    for(int i = 0; i < n; i++) {
        if(i < f) A[i] = -A[i];
        A[i] += maxp;
    }
     for(int i = 0; i < m; i++) {
        if(i < g) B[i] = -B[i];
        B[i] += maxp;
    }
    cnt_sort(A);
    cnt_sort(B);
    vector <int> mindiff(B.size(), INF);
    for(idB = 0; idB < B.size(); idB++) {
        while(idA < A.size() && A[idA] <= B[idB]) {
            idA++;
        }
        if(idA > 0) {
            mindiff[idB] = min(mindiff[idB], B[idB] - A[idA - 1]);
        }
    }
    idA = A.size() - 1;
    for(idB = B.size() - 1; idB >= 0; idB--) {
        while(idA > 0 && B[idB] <= A[idA]) {
            idA--;
        }
        if(idA + 1 < A.size()) {
            mindiff[idB] = min(mindiff[idB], A[idA + 1] - B[idB]);
        }
    }
    cnt_sort(mindiff);
    reverse(mindiff.begin(), mindiff.end());
    cout << mindiff.size() << '\n';
    for(auto ans : mindiff) {
        cout << ans + maxp << ' ';
    }
    return 0;
}
