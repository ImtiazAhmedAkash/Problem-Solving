/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Remove Exactly Two

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
    vector<set<int>> G(n + 1);
    vector<int> degree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
        degree[u]++;
        degree[v]++;
    }
    
    set<pair<int, int>> ms;
    for (int i = 1; i <= n; i++) {
        ms.insert({degree[i], i});
    }
    
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        auto [degU, u] = *prev(ms.end());
        ms.erase(prev(ms.end()));
        for (auto [degV, v] : ms) {
            if (G[u].find(v) == G[u].end()) {
                ans = max(ans, degU + degV - 1);
            } else {
                ans = max(ans, degU + degV - 2);
            }
        }
    }
    
    cout << ans << nl;
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