/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Tree Matching

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
    int n;
    cin >> n;
    vector G(n + 1, vector<int>());
    vector<int> degree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        degree[u]++, degree[v]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) {
            q.push(i);
        }
    }
    
    int ans = 0;
    vector<bool> used(n + 1, false);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        degree[u] = 0;
        for (auto &v : G[u]) {
            if (!used[u] && !used[v]) {
                used[u] = true;
                used[v] = true;
                ans++;
            }
            degree[v] = max(0, degree[v] - 1);
            if (degree[v] == 1) {
                q.push(v);
            }
        }
    }
    
    cout << ans << nl;
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