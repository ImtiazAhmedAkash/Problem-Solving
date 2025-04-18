/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Snowflake Tree

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
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    int ans = 0;
    for (int u = 1; u <= n; u++) {
        vector<int> A;
        for (auto &v : G[u]) {
            A.push_back(G[v].size() - 1);
        }
        
        sort(A.begin(), A.end(), greater());
        
        int m = A.size();
        for (int i = 0; i < m; i++) {
            ans = max(ans, 1 + (i + 1) + (i + 1) * A[i]);
        }
    }
    
    cout << n - ans << nl;
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