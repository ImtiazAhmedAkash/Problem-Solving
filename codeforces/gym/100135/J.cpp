/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bad Substring

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
    int n;
    cin >> n;

    vector dp(n, vector<ll>(3, -1));
    auto fun = [&](auto&& self, int indx, int last) -> ll {
        if (indx == n) return 1;
        if (dp[indx][last] != -1) return dp[indx][last];
        ll ans = 0;
        for (int i = 0; i < 3; i++) {
            if (last == 0 && i == 1) continue;
            ans += self(self, indx + 1, i);
        }
        return dp[indx][last] = ans;
    };

    cout << fun(fun, 0, 2) << nl;
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