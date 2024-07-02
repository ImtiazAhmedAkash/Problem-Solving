/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Socks

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> C(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> C[i];
    }
    vector G(n + 1, vector<int>());
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    map<int, int> cnt;
    vector<bool> used(n + 1, false);
    int tot = 0, mx_cnt = 0;

    auto dfs = [&](auto&& self, int u) -> void {
        used[u] = true;
        cnt[C[u]]++;
        tot++;
        mx_cnt = max(mx_cnt, cnt[C[u]]);

        for (auto v : G[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
    };

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            tot = 0;
            mx_cnt = 0;
            cnt.clear();
            dfs(dfs, i);
            ans += tot - mx_cnt;
        }
    }
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