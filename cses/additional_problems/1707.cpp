/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Graph Girth

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
    vector G(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    auto bfs = [&](int src) -> int {
        queue<int> q;
        q.push(src);
        vector<int> dist(n + 1, inf);
        dist[src] = 0;
        int cur = inf;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &v : G[u]) {
                if (dist[u] == dist[v]) {
                    cur = min(cur, 2 * dist[v] + 1);
                }
                if (dist[u] + 1 == dist[v]) {
                    cur = min(cur, 2 * dist[v]);
                }
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return cur;
    };

    int ans = inf;
    for (int i = 1; i <= n; i++) {
        ans = min(ans, bfs(i));
    }

    cout << (ans == inf ? -1 : ans) << nl;
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