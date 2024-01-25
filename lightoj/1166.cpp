/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1166 - Old Sorting

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
    for (int u = 1; u <= n; u++) {
        int v;
        cin >> v;
        G[u].push_back(v);
    }

    vector<bool> used(n + 1);
    int cnt = 0;
    auto dfs = [&](auto&& self, int u) -> void {
        used[u] = true;
        cnt++;
        for (auto v : G[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
    };

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            cnt = 0;
            dfs(dfs, i);
            ans += cnt - 1;
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
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}