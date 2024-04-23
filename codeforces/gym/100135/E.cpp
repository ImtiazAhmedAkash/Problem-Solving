/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Slalom

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
    vector A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> A[i][j];
        }
    }

    vector dp(n, vector<int>(n, -1));
    auto fun = [&](auto&& self, int row, int col) -> int {
        if (row == n) return 0;
        if (dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = A[row][col] + max(self(self, row + 1, col), self(self, row + 1, col + 1));
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