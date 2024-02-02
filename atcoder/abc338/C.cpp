/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Leftover Recipes

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e6 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> Q(n), A(n), B(n);
    for (auto &x : Q) cin >> x;
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;

    int lim = inf;
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) continue;
        lim = min(lim, Q[i] / A[i]);
    }
    int ans = 0;
    for (int a = 0; a <= lim; a++) {
        auto P = Q;
        for (int i = 0; i < n; i++) {
            P[i] -= A[i] * a;
        }
        int b = inf;
        for (int i = 0; i < n; i++) {
            if (B[i] == 0) continue;
            b = min(b, P[i] / B[i]);
        }
        ans = max(ans, a + b);
    }
    cout << ans << nl;
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