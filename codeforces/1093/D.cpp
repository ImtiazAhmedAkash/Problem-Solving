/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Beautiful Graph

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b /= 2;
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool ok = true;
    vector<int> color(n + 1, -1);
    vector<int> cnt(2, 0);

    auto dfs = [&](auto&& self, int u, int col) -> void {
        color[u] = col;
        cnt[col]++;
        for (auto& v : G[u]) {
            if (color[v] == -1) {
                self(self, v, 1 - col);
            } else if (color[v] == col) {
                ok = false;
            }
        }
    };

    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            ok = true;
            cnt[0] = cnt[1] = 0;
            dfs(dfs, i, 0);
            if (not ok) {
                cout << 0 << nl;
                return;
            }
            ll cur = power(2, cnt[0]);
            if (cur >= mod) cur -= mod;
            cur += power(2, cnt[1]);
            if (cur >= mod) cur -= mod;

            ans = (ans * cur) % mod;
        }
    }

    cout << ans << nl;
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