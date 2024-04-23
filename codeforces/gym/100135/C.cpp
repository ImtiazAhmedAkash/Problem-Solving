/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Knight’s move

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
    int n, m;
    cin >> n >> m;

    vector dp(n, vector<ll>(m, -1));
    auto fun = [&](auto&& self, int x, int y) -> ll {
        if (x >= n || y >= m) return 0;
        if (x == n - 1 && y == m - 1) return 1;
        if (dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = self(self, x + 1, y + 2) + self(self, x + 2, y + 1);
    };

    cout << fun(fun, 0, 0) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}