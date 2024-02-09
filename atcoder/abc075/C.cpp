/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bridge

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1, vector<int>(n + 1, 0));
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    
    int cnt = 0;
    vector<bool> used(n + 1);
    
    auto dfs = [&](auto&& self, int u) -> void {
        used[u] = true;
        cnt++;
        for (int v = 1; v <= n; v++) {
            if (G[u][v] && !used[v]) {
                self(self, v);
            }
        }
    };
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (G[i][j] == 0) continue;
            
            G[i][j] = G[j][i] = 0;
            cnt = 0;
            fill(used.begin(), used.end(), false);
            dfs(dfs, 1);
            if (cnt != n) {
                ans++;
            }
            G[i][j] = G[j][i] = 1;
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