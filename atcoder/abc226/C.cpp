/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Martial artist

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
    vector G(n + 1, vector<int>());
    vector<int> T(n + 1), used(n + 1, false);
    for (int i = 1; i <= n; i++) {
        cin >> T[i];
        int x;
        cin >> x;
        G[i].resize(x);
        for (int j = 0; j < x; j++) {
            cin >> G[i][j];
        }
    }

    auto dfs = [&](auto&& self, int u) -> ll {
        ll cur = T[u];
        used[u] = true;
        for (auto v : G[u]) {
            if (!used[v]) {
                cur += self(self, v);
            }
        }
        return cur;
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