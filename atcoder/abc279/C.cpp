/*  In the Name of ALLAH, the most gracious, the most merciful  */

// RANDOM

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 3e5;

void solve() {
    int h, w;
    cin >> h >> w;
    vector<string> A(h), B(h);
    for (int i = 0; i < h; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < h; i++) {
        cin >> B[i];
    }
    vector<string> C(w), D(w);
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < h; i++) {
            C[j].push_back(A[i][j]);
            D[j].push_back(B[i][j]);
        }
    }
    sort(C.begin(), C.end());
    sort(D.begin(), D.end());
    cout << (C == D ? " Yes" : "No") << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}