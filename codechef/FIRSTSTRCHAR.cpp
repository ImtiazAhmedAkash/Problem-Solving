/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// FIRSTSTRCHAR - Replace With First Literally

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
    string s, t;
    cin >> s >> t;

    if (s == t) {
        cout << 0 << nl;
        return;
    }
    if (s.front() != t.front()) {
        cout << -1 << nl;
        return;
    }

    vector dp(n, vector(m, vector<int>(2, -1)));
    auto fun = [&](auto&& self, int i, int j, int op) -> int {
        if (j == m) {
            return (i == n || op ? 0 : 1);
        }
        if (i == n) return inf;
        auto& ans = dp[i][j][op];
        if (~ans) return ans;

        ans = inf;
        ans = min(ans, 1 - op + self(self, i + 1, j, 1));
        if (s[i] == t[j]) {
            ans = min(ans, self(self, i + 1, j + 1, 0));
        }
        return ans;
    };

    int ans = fun(fun, 0, 0, 0);
    cout << (ans >= inf ? -1 : ans) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}