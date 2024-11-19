/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Investigation

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<>>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector G(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }

    vector<ll> dist(n + 1, INF);
    min_heap<array<ll, 2>> pq;
    dist[1] = 0;
    pq.push({0, 1});

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

    vector<ll> dist2(n + 1, INF);
    vector<int> path(n + 1, 0);
    vector<int> min_flight(n + 1, inf), max_flight(n + 1, 0);
    path[1] = 1;
    min_flight[1] = 0;
    dist2[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cdist, u] = pq.top();
        pq.pop();

        if (dist2[u] != cdist) continue;

        for (auto &[v, w] : G[u]) {
            if (dist2[u] + w < dist2[v]) {
                dist2[v] = dist2[u] + w;
                pq.push({dist2[v], v});
            }

            if (cdist + w == dist[v]) {
                path[v] += path[u];
                if (path[v] >= mod) {
                    path[v] -= mod;
                }
                min_flight[v] = min(min_flight[v], min_flight[u] + 1);
                max_flight[v] = max(max_flight[v], max_flight[u] + 1);
            }
        }
    }

    cout << dist[n] << " " << path[n] << " " << min_flight[n] << " " << max_flight[n] << nl;
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