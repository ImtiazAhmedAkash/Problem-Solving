/*  In the Name of ALLAH, the most gracious, the most merciful  */

// ±1 Operation 1

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e6;

void solve() {
    ll x, a, d, n;
    cin >> x >> a >> d >> n;

    if (d == 0) {
        cout << abs(x - a) << nl;
        return;
    }

    auto pth_term = [&](ll p) -> ll {
        return a + (p - 1) * d;
    };

    ll ans = min(abs(x - a), abs(x - pth_term(n)));
    ll term = max(1LL, ((x - a) / d) + 1);
    if (term <= n) {
        ans = min(ans, abs(x - pth_term(term)));
    }
    if (term + 1 <= n) {
        ans = min(ans, abs(x - pth_term(term + 1)));
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