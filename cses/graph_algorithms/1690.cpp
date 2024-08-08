/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Hamiltonian Flights

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
    int n, m;
    cin >> n >> m;
    vector G(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
    }

    vector dp(n, vector<int>(1 << n, -1));
    // dp[i][mask] -> no. of ways to go from i-th city to n-th city with the mask (available city)

    auto fun = [&](auto&& self, int cur, int mask) -> int {
        if (cur == n - 1) {
            return (mask == 0 ? 1 : 0);
        }
        auto& ans = dp[cur][mask];
        if (ans != -1) return ans;

        ans = 0;
        for (auto v : G[cur]) {
            if (mask & (1 << v)) {
                ans = (0LL + ans + self(self, v, mask ^ (1 << v))) % mod;
            }
        }
        return ans;
    };

    cout << fun(fun, 0, ((1 << n) - 1) ^ 1) << nl;
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