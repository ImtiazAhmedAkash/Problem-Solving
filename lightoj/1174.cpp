/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1174 - Commandos

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
    vector G(n, vector<int>());
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int start, target;
    cin >> start >> target;

    auto bfs = [&](int src, vector<int> &dist) -> void {
        queue<int> Q;
        Q.push(src);
        dist[src] = 0;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto v : G[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                }
            }
        }
    };

    vector<int> dist_from_start(n, inf);
    vector<int> dist_from_end(n, inf);

    bfs(start, dist_from_start);
    bfs(target, dist_from_end);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dist_from_start[i] + dist_from_end[i]);
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