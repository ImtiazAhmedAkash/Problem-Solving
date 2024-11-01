/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// ADATRIP - Ada and Trip

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<>>;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<pair<int, int>>> G(n, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    vector<pair<int, int>> ans(n, {-1, -1});
    auto dijkstra = [&](int src) -> void {
        vector<int> dist(n, inf);
        dist[src] = 0;
        min_heap<array<int, 2>> pq;
        pq.push({dist[src], src});

        while (!pq.empty()) {
            auto [cdist, u] = pq.top();
            pq.pop();

            if (dist[u] != cdist) continue;

            for (auto &[v, w] : G[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int max_dist = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] != inf) {
                max_dist = max(max_dist, dist[i]);
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (dist[i] == max_dist) cnt++;
        }

        ans[src] = {max_dist, cnt};
    };

    while (q--) {
        int x;
        cin >> x;
        if (ans[x] == make_pair(-1, -1)) {
            dijkstra(x);
        }
        cout << ans[x].first << " " << ans[x].second << nl;
    }
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