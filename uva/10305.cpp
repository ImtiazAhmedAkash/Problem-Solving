/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 10305 - Ordering Tasks

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 100;

vector<vector<int>> G(N + 5, vector<int>());
vector<bool> used(N + 5, false);
stack<int> ans;

void dfs(int u) {
    used[u] = true;
    for (auto v : G[u]) {
        if (!used[v]) {
            dfs(v);
        }
    }
    ans.push(u);
}

void solve() {
    int n, m;
    while (cin >> n >> m && n) {
        for (int i = 1; i <= n; i++) {
            G[i].clear();
            used[i] = false;
        }

        while (m--) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
        }
        for (int u = 1; u <= n; u++) {
            if (!used[u]) {
                dfs(u);
            }
        }
        while (!ans.empty()) {
            cout << ans.top() << " \n"[ans.size() == 1];
            ans.pop();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}