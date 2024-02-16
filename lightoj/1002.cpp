/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1002 - Country Roads

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
    vector G(n, vector<pair<int, int>>());
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    int target;
    cin >> target;

    vector<int> cost(n, inf);
    auto dijkstra = [&](int src) -> void {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        cost[src] = 0;
        pq.push({cost[src], src});
        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (cost[u] != d) continue;

            for (auto [v, wt] : G[u]) {
                if (max(cost[u], wt) < cost[v]) {
                    cost[v] = max(cost[u], wt);
                    pq.push({cost[v], v});
                }
            }
        }
    };

    dijkstra(target);
    for (int i = 0; i < n; i++) {
        if (cost[i] == inf) {
            cout << "Impossible" << nl;
        } else {
            cout << cost[i] << nl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": " << nl;
        solve();
    }

    return 0;
}