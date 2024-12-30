/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Course Schedule

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
    int n, m;
    cin >> n >> m;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    
    vector<int> order;
    vector<int> used(n + 1, false);
    auto dfs = [&](auto&& self, int u) -> void {
        used[u] = true;
        for (auto &v : G[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
        order.push_back(u);
    };
    
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            dfs(dfs, i);
        }
    }
    
    reverse(order.begin(), order.end());
    
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[order[i]] = i;
    }
    
    for (int u = 1; u <= n; u++) {
        for (auto &v : G[u]) {
            if (pos[u] >= pos[v]) {
                cout << "IMPOSSIBLE" << nl;
                return;
            }
        }
    }
    
    for (auto &x : order) {
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