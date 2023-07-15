/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Isolation

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1LL << 62)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

vector<set<int>> g(N);

void solve() {
    int n, q;
    cin >> n >> q;
    
    int ans = n;
    while (q--) {
        int a, u, v;
        cin >> a;
        if (a == 1) {
            cin >> u >> v;
            if (g[u].empty()) ans--;
            g[u].insert(v);
            if (g[v].empty()) ans--;
            g[v].insert(u);
        }
        else {
            cin >> v;
            for (auto i : g[v]) {
                if (!g[i].empty()) {
                    g[i].erase(v);
                    if (g[i].empty()) ans++;
                }
            }
            if (!g[v].empty()) {
                g[v].clear();
                ans++;
            }
        }
        
        cout << ans << nl;
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
    