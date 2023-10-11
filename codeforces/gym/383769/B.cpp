/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Path Finding

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1];
    
    int start, end;
    cin >> start >> end;
    
    while (m--) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    vector<bool> vis(n + 1, false);
    vector<int> nxt(n + 1);
    
    queue<int> q;
    q.push(end);
    vis[end] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (vis[v]) continue;
            q.push(v);
            vis[v] = 1;
            nxt[v] = u;
        }
    }
    vector<int> ans;
    ans.push_back(start);
    int i = start;
    while (1) {
        i = nxt[i];
        ans.push_back(i);
        if (i == end) break;
    }
    
    cout << ans.size() << nl;
    for (auto x : ans) cout << x << " ";
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}