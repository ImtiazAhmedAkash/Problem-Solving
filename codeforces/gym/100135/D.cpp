/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Path Cost

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
    int n = 8;
    vector grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector dp(n, vector<int>(n, -1));
    auto fun = [&](auto&& self, int x, int y) -> int {
        if (x == n - 1 && y == 0) return 0;
        if (x >= n || y < 0) return inf;
        if (dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = grid[x][y] + (min({self(self, x, y - 1), self(self, x + 1, y - 1), self(self, x + 1, y)}));
    };

    cout << fun(fun, 0, n - 1) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("king2.in", "r", stdin);
    freopen("king2.out", "w", stdout);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}