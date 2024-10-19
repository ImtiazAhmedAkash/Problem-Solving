/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Ant on the Tree

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
    vector<int> nodes = {1};
    int k;
    while (cin >> k) {
        nodes.push_back(k);
    }
    nodes.push_back(1);

    vector<int> ans;
    bool done = false;
    auto dfs = [&](auto&& self, int u, int target, int par = 0) -> void {
        if (ans.empty() || ans.back() != u) {
            ans.push_back(u);
        }
        if (target == u) done = true;
        if (done) return;

        for (auto &v : G[u]) {
            if (done) return;
            if (v == par) continue;
            self(self, v, target, u);
        }

        if (!done) ans.pop_back();
    };

    for (int i = 0; i + 1 < nodes.size(); i++) {
        done = false;
        dfs(dfs, nodes[i], nodes[i + 1]);
    }

    if (ans.size() > 2 * n - 1) {
        cout << -1 << nl;
        return;
    }
    
    for (auto &x : ans) {
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