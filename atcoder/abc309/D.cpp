/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Add One Edge

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

vector<int> g[N];
vector<bool> vis(N, false);
vector<int> lvl(N, 0);
void solve() {
    int n1, n2, m;
    cin >> n1 >> n2 >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;

    auto bfs = [&](int src) {
        int mx_dist = 0;
        queue<int> q;
        q.push(src);
        vis[src] = true;
        lvl[src] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : g[u]) {
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                    lvl[v] = lvl[u] + 1;
                    mx_dist = max(mx_dist, lvl[v]);
                }
            }
        }
        return mx_dist;
    };
    
    ans += bfs(1);
    ans += bfs(n1 + n2);
    
    cout << ans + 1 << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}