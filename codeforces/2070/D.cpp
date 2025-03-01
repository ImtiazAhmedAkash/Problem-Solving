/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Tree Jumps

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector G(n + 1, vector<int>());
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        G[i].push_back(p);
        G[p].push_back(i);
    }
    
    vector<ll> dp(n + 1), sum(n + 1);
    auto bfs = [&](int src) -> void {
        vector<int> dist(n + 1, inf), par(n + 1, 0);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (dist[u] <= 1) {
                dp[u]++;
                dp[u] %= mod;
                sum[dist[u]]++;
                sum[dist[u]] %= mod;
            }
            else {
                dp[u] = (sum[dist[par[u]]] - dp[par[u]] + mod) % mod;
                sum[dist[u]] += dp[u];
                sum[dist[u]] %= mod;
            }
            for (auto &v : G[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    par[v] = u;
                    q.push(v);
                }
            }
        }
    };
    bfs(1);
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i];
        ans %= mod;
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