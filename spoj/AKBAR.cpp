/*  In the Name of ALLAH, the most gracious, the most merciful  */

// AKBAR - Akbar , The great

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
    int n, r, m;
    cin >> n >> r >> m;
    vector<int> G[n + 1];
    while (r--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> city(m), power(m);
    for (int i = 0; i < m; i++) {
        cin >> city[i] >> power[i];
    }
    
    vector<int> dist(n + 1, -1);
    auto bfs = [&](int src, int power) {
        bool effect = false;
        if (dist[src] == -1) effect = true;
        dist[src] = 0;
        queue<int> Q;
        Q.push(src);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto v : G[u]) {
                if (dist[v] == -1 && dist[u] + 1 <= power) {
                    effect = true;
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                }
            }
        }
        return effect;
    };
    
    bool ok = true;
    for (int i = 0; i < m; i++) {
        ok &= bfs(city[i], power[i]);
    }
    if (ok) {
        ok = all_of(dist.begin() + 1, dist.end(), [&](int i){return i != -1;});
    }
    cout << (ok ? "Yes" : "No") << nl;
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