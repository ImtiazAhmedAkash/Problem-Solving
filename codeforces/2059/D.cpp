/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Graph and Graph

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

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<>>;

void solve() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    int m1;
    cin >> m1;
    vector G1(n + 1, vector<int>());
    set<pair<int, int>> edge1;
    for (int i = 0; i < m1; i++) {
        int u, v;
        cin >> u >> v;
        G1[u].push_back(v);
        G1[v].push_back(u);
        edge1.insert({min(u, v), max(u, v)});
    }
    int m2;
    cin >> m2;
    vector G2(n + 1, vector<int>());
    set<pair<int, int>> edge2;
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        G2[u].push_back(v);
        G2[v].push_back(u);
        edge2.insert({min(u, v), max(u, v)});
    }
    
    vector dist(n + 1, vector<ll>(n + 1, INF));
    dist[s1][s2] = 0;
    min_heap<array<ll, 3>> pq;
    pq.push({0, s1, s2});
    
    while (!pq.empty()) {
        auto [d, u1, u2] = pq.top();
        pq.pop();
        
        if (dist[u1][u2] != d) continue;
        
        for (auto &v1 : G1[u1]) {
            for (auto &v2 : G2[u2]) {
                if (dist[u1][u2] + abs(v1 - v2) < dist[v1][v2]) {
                    dist[v1][v2] = dist[u1][u2] + abs(v1 - v2);
                    pq.push({dist[v1][v2], v1, v2});
                }
            }
        }
    }
    
    ll ans = INF;
    for (auto &[x, y] : edge1) {
        if (edge2.find({x, y}) != edge2.end()) {
            ans = min({ans, dist[x][x], dist[y][y]});
        }
    }
    
    cout << (ans >= INF ? -1 : ans) << nl;
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