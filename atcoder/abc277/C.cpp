/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Ladder Takahashi

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
    map<int, vector<int>> M;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        M[u].push_back(v);
        M[v].push_back(u);
    }
    int ans = 0;
    map<int, bool> used;

    auto dfs = [&](auto&& self, int u) -> void {
        used[u] = true;
        ans = max(ans, u);
        for (auto v : M[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
    };

    dfs(dfs, 1);
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