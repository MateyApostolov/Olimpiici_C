#include <bits/stdc++.h>
using namespace std;

vector<vector<long long>> adj_mat;
vector<vector<long long>> id_mat;

vector<vector<long long>> mul(vector<vector<long long>> A, vector<vector<long long>> B) {
    vector<vector<long long>> rez;
    rez.resize(n);
    for(int i = 0; i < n; i++) {
        rez[i].resize(n, 0);
    }
    for(int i = 0; i < n; i++) {
        for(int t = 0; t < n; t++) {
            for(int j = 0; j < n; j++) {
                rez[i][j] += A[i][t] * B[t][j];
                rez[i][j] %= mod;
            }
        }
    }
    return rez;
}

vector<vector<long long>> fast_step(vector<vector<long long>> M, int power) {
    if(power == 0) return id_mat;
    if(power == 1) return M;
    vector<vector<long long>> rez = fast_step(M, power / 2);
    rez = mul(rez, rez);
    if(power % 2 == 1) {
        rez = mul(rez, M);
    }
    return rez;
}

int main () {
    int n;
    float p;
    cin >> n >> p;
    adj_mat.resize(n);
    id_mat.resize(n);
    for(int i = 0; i < n; i++) {
        adj_mat[i].resize(n, 0);
        id_mat[i].resize(n, 0);
        id_mat[i][i] = 1;
    }
    adj[]
    vector<vector<long long>> rez = fast_step(adj_mat, k);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans = (ans + rez[i][j]) % mod;
        }
    }
    cout << ans;

    return 0;
}
