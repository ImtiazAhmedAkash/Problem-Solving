/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Toward 0

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    ll n, a, x, y;
    cin >> n >> a >> x >> y;

    map<ll, ld> dp;
    auto fun = [&](auto&& self, ll n) -> ld {
        if (n == 0) return 0;
        if (dp.find(n) != dp.end()) return dp[n];
        ld replace = x + self(self, n / a);
        ld tmp = 0;
        for (int i = 2; i <= 6; i++) {
            tmp += self(self, n / i);
        }
        ld dice = (y + tmp / 6.0) * 6.0 / 5.0;
        return dp[n] = min(replace, dice);
    };

    ld ans = fun(fun, n);
    cout << fixed << setprecision(12) << ans << nl;
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