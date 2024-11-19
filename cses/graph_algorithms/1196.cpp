/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Flight Routes

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
    int n, m, k;
    cin >> n >> m >> k;
    
    vector G(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
    }
    
    vector<multiset<ll>> dist(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            dist[i].insert(INF);
        }
    }
    
    min_heap<array<ll, 2>> pq;
    dist[1].erase(dist[1].begin());
    dist[1].insert(0);
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [cdist, u] = pq.top();
        pq.pop();
        
        if (dist[u].find(cdist) == dist[u].end()) continue;
        
        for (auto &[v, w] : G[u]) {
            if (cdist + w < *dist[v].rbegin()) {
                dist[v].insert(cdist + w);
                dist[v].erase(--dist[v].end());
                pq.push({cdist + w, v});
            }
        }
    }
    
    for (auto &x : dist[n]) {
        cout << x << " ";
    }
    cout << nl;
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