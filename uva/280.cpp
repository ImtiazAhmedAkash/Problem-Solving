/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Vertex

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 105;
vector<vector<int>> G(N, vector<int>());
vector<bool> used;

void dfs(int u) {
    for (auto v : G[u]) {
        if (!used[v]) {
            used[v] = true;
            dfs(v);
        }
    }
}

void solve() {
    int n;
    while (cin >> n && n) {
        G.resize(n + 1, vector<int>());
        for (int i = 1; i <= n; i++) G[i].clear();
        used.resize(n + 1, false);
        int u;
        while (cin >> u && u) {
            int v;
            while (cin >> v && v) {
                G[u].push_back(v);
            }
        }
        
        int q;
        cin >> q;
        while (q--) {
            int x;
            cin >> x;
            fill(used.begin(), used.end(), false);
            dfs(x);
            vector<int> ans;
            for (int i = 1; i <= n; i++) {
                if (!used[i]) {
                    ans.push_back(i);
                }
            }
            cout << ans.size();
            for (auto z : ans) cout << " " << z;
            cout << nl;
        }
    }
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