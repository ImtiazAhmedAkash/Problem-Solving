/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Mail Stamps

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
    map<int, int> M, A;
    vector G(2 * n + 5, vector<int>());
    int id = 1;
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        if (M.find(u) == M.end()) {
            A[id] = u;
            M[u] = id++;
        }
        u = M[u];
        if (M.find(v) == M.end()) {
            A[id] = v;
            M[v] = id++;
        }
        v = M[v];
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<bool> used(id, false);
    vector<int> ans;
    auto dfs = [&](auto&& self, int u) -> void {
        used[u] = true;
        ans.push_back(u);
        for (auto v : G[u]) {
            if (!used[v]) {
                self(self, v);
            }
        }
    };

    for (int i = 1; i < id; i++) {
        if (G[i].size() == 1) {
            dfs(dfs, i);
            break;
        }
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << A[ans[i]] << " \n"[i + 1 == ans.size()];
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