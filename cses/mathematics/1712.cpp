/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Exponentiation II

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const ll M = 1e9 + 7;
const int N = 2e5 + 5;

ll power(ll a, ll b, ll mod) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    ll x = power(b, c, M - 1);
    ll ans = power(a, x, M);
    cout << ans << nl;
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