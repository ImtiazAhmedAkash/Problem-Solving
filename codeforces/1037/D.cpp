/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Valid BFS?

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
    vector<int> G[n + 1];
    for (int i = 1; i + 1 <= n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> A(n), pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        pos[A[i]] = i;
    }
    
    auto comp = [&](int x, int y) {
        return pos[x] < pos[y];
    };
    
    for (int i = 1; i <= n; i++) {
        sort(G[i].begin(), G[i].end(), comp);
    }
    vector<int> B;
    
    auto bfs = [&](int src) {
        vector<int> dist(n + 1, -1);
        dist[src] = 0;
        queue<int> Q;
        Q.push(src);
        while (!Q.empty()) {
            int u = Q.front();
            B.push_back(u);
            Q.pop();
            for (auto v : G[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                }
            }
        }
    };
    
    bfs(1);
    cout << (A == B ? "Yes" : "No") << nl;
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