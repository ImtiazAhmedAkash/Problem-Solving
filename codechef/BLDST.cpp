/*  In the Name of ALLAH, the most gracious, the most merciful  */

// BLDST - Ball Distribution

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
    vector<int> A(m);
    for (auto &x : A) cin >> x;

    int good = 0, bad = n;
    for (int i = 0; i < m; i++) {
        int x = min(A[i], good);
        bad = A[i] - x;
        good = n - bad;
    }
    cout << bad << nl;
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