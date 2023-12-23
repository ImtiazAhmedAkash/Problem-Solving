/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Remainder Minimization 2019

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 2019;
const int N = 2e5 + 5;

void solve() {
    ll l, r;
    cin >> l >> r;
    ll ans = inf;
    for (ll i = l; i < min(l + mod, r); i++) {
        for (ll j = i + 1; j <= min(l + mod, r); j++) {
            ans = min(ans, ((i % mod) * (j % mod)) % mod);
        }
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