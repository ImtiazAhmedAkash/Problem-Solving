/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// EAGLE1 - Eagle and Dogs

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
    vector<vector<pair<int, int>>> G(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    
    auto bfs = [&](int src, vector<ll>& dist) -> int {
        dist.assign(n + 1, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            
            for (auto &[v, w] : G[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + w;
                    q.push(v);
                }
            }
        }
        return max_element(dist.begin(), dist.end()) - dist.begin();
    };
    
    vector<ll> dog_x, dog_y;
    int x = bfs(1, dog_x);
    int y = bfs(x, dog_x);
    bfs(y, dog_y);
    
    for (int i = 1; i <= n; i++) {
        cout << max(dog_x[i], dog_y[i]) << " \n"[i == n];
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