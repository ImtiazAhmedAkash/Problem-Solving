/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// G1 - Medium Demon Problem (easy version)

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
    vector<int> indegree(n + 1, 0);
    for (int u = 1; u <= n; u++) {
        int v;
        cin >> v;
        G[u].push_back(v);
        indegree[v]++;
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }
    
    int ans = 1;
    while (!q.empty()) {
        ans++;
        int m = q.size();
        while (m--) {
            int u = q.front();
            q.pop();
            for (auto &v : G[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }
    }
    
    cout << ans + 1 << nl;
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