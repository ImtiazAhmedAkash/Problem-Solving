/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Divide and Divide

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
    ll n;
    cin >> n;
    map<ll, ll> M;

    auto dfs = [&](auto&& self, ll x) -> ll {
        if (x == 1) return 0;
        if (M.find(x) != M.end()) return M[x];
        return M[x] = x + self(self, x / 2) + self(self, (x + 1) / 2);
    };

    ll ans = dfs(dfs, n);

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