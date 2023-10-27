/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Dominos 2 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 10005;
vector<int> G[N];
vector<bool> used(N);

void dfs(int u) {
    used[u] = true;
    for (auto v : G[u]) {
        if (!used[v]) {
            dfs(v);
        }
    }
}

void solve() {
    int n, m, l;
    cin >> n >> m >> l;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        used[i] = false;
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }
    while (l--) {
        int src;
        cin >> src;
        if (!used[src]) {
            dfs(src);
        }
    }
    cout << count(used.begin(), used.begin() + n + 1, true) << nl;
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