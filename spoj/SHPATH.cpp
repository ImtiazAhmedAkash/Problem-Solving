/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// SHPATH - The Shortest Path

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
using min_heap = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n;
    cin >> n;
    map<string, int> mp;
    vector<vector<pair<int, int>>> G(n + 1, vector<pair<int, int>>());
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        mp[s] = i;

        int k;
        cin >> k;
        while (k--) {
            int v, w;
            cin >> v >> w;
            G[i].push_back({v, w});
        }
    }

    auto dijkstra = [&](int src, int goal) -> int {
        min_heap<array<int, 2>> pq;
        vector<int> dist(n + 1, inf);
        dist[src] = 0;
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

        return dist[goal];
    };

    int q;
    cin >> q;
    while (q--) {
        string a, b;
        cin >> a >> b;
        cout << dijkstra(mp[a], mp[b]) << nl;
    }
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