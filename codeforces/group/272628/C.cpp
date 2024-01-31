/*  In the Name of ALLAH, the most gracious, the most merciful  */

// The Pharaohs

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

void solve() {
    ll n;
    cin >> n;
    ll L = 1, R = inf + inf;
    while (L <= R) {
        ll M = L + (R - L) / 2;
        ll mx = M * (M + 1) / 2;
        ll mn = mx - M + 1;
        if (mn <= n && n <= mx) {
            cout << M << nl;
            return;
        } else if (mx < n) {
            L = M + 1;
        } else {
            R = M - 1;
        }
    }
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