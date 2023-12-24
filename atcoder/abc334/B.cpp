/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Christmas Trees

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
    ll a, m, l, r;
    cin >> a >> m >> l >> r;

    auto floor = [&](ll p, ll q) {
        ll rem = ((p % q) + q) % q;  // positive remainder
        return (p - rem) / q;
    };

    l -= a;
    r -= a;
    ll ans = floor(r, m) - floor(l - 1, m);
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