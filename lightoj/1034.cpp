/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1034 - Hit the Light Switches

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
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    
    vector<bool> used(n + 1, false);
    stack<int> stk;
    
    auto topo_sort = [&](auto self, int u) -> void {
        used[u] = true;
        for (auto v : G[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
        stk.push(u);
    };
    
    for (int u = 1; u <= n; u++) {
        if (!used[u]) {
            topo_sort(topo_sort, u);
        }
    }
    
    fill(used.begin(), used.end(), false);
    auto dfs = [&](auto self, int u) -> void {
        used[u] = true;
        for (auto v : G[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
    };
    
    int ans = 0;
    while (!stk.empty()) {
        if (!used[stk.top()]) {
            dfs(dfs, stk.top());
            ans++;
        }
        stk.pop();
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}