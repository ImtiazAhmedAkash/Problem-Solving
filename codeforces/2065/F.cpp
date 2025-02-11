/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Skibidus and Slay

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector G(n + 1, vector<int>());
    vector<int> ans(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        if (A[u] == A[v]) ans[A[u]] = 1;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    for (int u = 1; u <= n; u++) {
        map<int, int> mp;
        for (auto &v : G[u]) {
            mp[A[v]]++;
            if (mp[A[v]] == 2) ans[A[v]] = 1;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i];
    }
    cout << nl;
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