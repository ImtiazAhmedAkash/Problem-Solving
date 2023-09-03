/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Copil Copac Draws Trees

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

vector<int> ans;
vector<int> g[N];
map<pair<int, int>, int> mp;

void dfs(int u, int par) {
    for (auto v : g[u]) {
        if (v == par) continue;
        if (mp[{u, v}] > mp[{u, par}]) ans[v] = ans[u];
        else ans[v] = ans[u] + 1;
        dfs(v, u);
    }
}

void solve() {
    int n;
    cin >> n;
    ans.resize(n + 1, 0);
    mp[{0, 1}] = mp[{1, 0}] = n + 1;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        mp[{u, v}] = mp[{v, u}] = i;
    }
    ans[1] = 0;
    dfs(1, 0);
    cout << *max_element(ans.begin(), ans.end()) << nl;
    mp.clear();
    for (int i = 1; i <= n; i++) g[i].clear();
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