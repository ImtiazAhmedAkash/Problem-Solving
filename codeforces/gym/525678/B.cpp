/*  In the Name of ALLAH, the most gracious, the most merciful  */

// No Ragging

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
    ll x, n, d;
    cin >> x >> n >> d;
    x = abs(x);

    ll ans = INF;
    ll move = min(n, x / d);

    n -= move;
    ll y = d * move;
    if (n % 2 == 0) {
        ans = min(ans, abs(x - y));
    } else {
        ans = min({ans, abs(x - y + d), abs(x - y - d)});
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