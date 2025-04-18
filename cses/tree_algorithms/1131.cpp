/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Tree Diameter

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
    int n;
    cin >> n;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    auto bfs = [&](int src, vector<int>& dist) -> int {
        dist.assign(n + 1, inf);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        int last = -1;
        
        while (!q.empty()) {
            auto u = q.front();
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
    
    vector<int> dist;
    int x = bfs(1, dist);
    int y = bfs(x, dist);
    
    cout << *max_element(dist.begin() + 1, dist.end()) << nl;
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