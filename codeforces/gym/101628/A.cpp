/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Arthur's Language

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
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();

    vector dp(n, vector<int>(m, -1));
    auto fun = [&](auto&& self, int i, int j) -> int {
        if (j < 0) return 1;
        if (i < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int skip = self(self, i - 1, j);
        int take = (a[i] == b[j] ? self(self, i - 1, j - 1) : 0);
        return dp[i][j] = (0LL + take + skip) % mod;
    };

    cout << fun(fun, n - 1, m - 1) << nl;
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