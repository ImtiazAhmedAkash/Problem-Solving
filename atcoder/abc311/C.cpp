/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Find it!

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 200005
#define deb(x) cerr << #x << " = " << x << nl

vector<int> g[N];
vector<bool> vis(N, false);
vector<int> pre(N);
bool ok = false;
int start = 0, End = 0;

void dfs(int u, int prev) {
    if (vis[u]) {
        ok = true;
        End = prev;
        start = pre[u];
        return;
    }

    vis[u] = true;
    pre[u] = prev;

    for (auto v : g[u]) {
        dfs(v, u);
        if (ok) return;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        g[i].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        dfs(i, 0);
        if (ok) break;
    }
    
    vector<int> ans;
    while (End != start) {
        ans.push_back(End);
        End = pre[End];
    }
    
    cout << ans.size() << nl;
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << " ";
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