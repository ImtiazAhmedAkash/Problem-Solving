/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Game on Tree (Easy)

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
    int n, q;
    cin >> n >> q;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    auto find_diameter = [&](int src, vector<int>& dist) -> int {
        dist.assign(n + 1, inf);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        int last = -1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &v : G[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
            last = u;
        }
        return last;
    };
    
    while (q--) {
        int k;
        cin >> k;
        vector<int> dist_x, dist_y;
        int leafOne = find_diameter(1, dist_x);
        int leafTwo = find_diameter(leafOne, dist_x);
        find_diameter(leafTwo, dist_y);
        
        cout << ((dist_x[k] & 1) || (dist_y[k] & 1) ? "Ron" : "Hermione") << nl;
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