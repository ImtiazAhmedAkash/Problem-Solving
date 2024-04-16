/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Journey by Train

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
    int n, root;
    cin >> n >> root;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int ans = 0;
    auto dfs = [&](auto&& self, int u, int par = -1, int cur) -> void {
        ans = max(ans, cur);
        for (auto v : G[u]) {
            if (par == v) continue;
            if (A[u] < A[v]) {
                self(self, v, u, cur + 1);
            }
        }
    };

    dfs(dfs, root, -1, 1);
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