/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Coloring

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(m);
    for (auto& x : A) cin >> x;

    int mx = (n + k - 1) / k;
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (mx < A[i]) {
            cout << "NO" << nl;
            return;
        }
        cnt += (A[i] == mx);
    }

    int lim = n % k;
    if (lim == 0) lim = k;
    cout << (cnt <= lim ? "YES" : "NO") << nl;
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