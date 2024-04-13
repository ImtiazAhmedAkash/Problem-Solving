/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Grid Paths

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<string> A(n);
    for (auto& x : A) cin >> x;

    vector dp(n, vector<int>(n, -1));
    auto fun = [&](auto&& self, int row, int col) -> int {
        if (row >= n || col >= n || A[row][col] == '*') return 0;
        if (row == n - 1 && col == n - 1) return 1;
        if (dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = (0LL + self(self, row + 1, col) + self(self, row, col + 1)) % mod;
    };

    cout << fun(fun, 0, 0) << nl;
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