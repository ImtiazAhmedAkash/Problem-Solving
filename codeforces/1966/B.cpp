/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Rectangle Filling

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    for (auto& x : A) cin >> x;

    bool r1 = true, rn = true;
    for (int j = 0; j < m; j++) {
        r1 &= A[0][0] == A[0][j];
        rn &= A[n - 1][0] == A[n - 1][j];
    }
    bool c1 = true, cm = true;
    for (int i = 0; i < n; i++) {
        c1 &= A[0][0] == A[i][0];
        cm &= A[0][m - 1] == A[i][m - 1];
    }

    cout << ((r1 && rn && A[0][0] != A[n - 1][0]) || (c1 && cm && A[0][0] != A[0][m - 1]) ? "NO" : "YES") << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}