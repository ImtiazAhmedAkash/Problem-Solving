/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Weak Takahashi

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
    int h, w;
    cin >> h >> w;
    vector<string> A(h);
    for (int i = 0; i < h; i++) {
        cin >> A[i];
    }
    vector dp(h, vector<int>(w, -1));

    auto fun = [&](auto&& self, int i, int j) -> int {
        if (i == h || j == w || A[i][j] == '#') return 0;
        if (~dp[i][j]) return dp[i][j];
        return dp[i][j] = 1 + max(self(self, i + 1, j), self(self, i, j + 1));
    };

    int ans = fun(fun, 0, 0);
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