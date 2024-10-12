/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Road Improvement

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
    map<pair<int, int>, int> mp;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);

        if (u > v) swap(u, v);
        mp[{u, v}] = i;
    }

    vector<set<int>> st(n + 1);
    vector<int> mex(n + 1, 1);

    auto find_mex = [&](int x) -> void {
        while (st[x].find(mex[x]) != st[x].end()) {
            mex[x]++;
        }
    };

    map<int, vector<int>> ans;
    auto dfs = [&](auto &&self, int u, int par = 0) -> void {
        for (auto &v : G[u]) {
            if (v == par) continue;
            int road = (u < v ? mp[{u, v}] : mp[{v, u}]);
            ans[mex[u]].push_back(road);
            st[u].insert(mex[u]);
            st[v].insert(mex[u]);
            find_mex(u);
            find_mex(v);
            self(self, v, u);
        }
    };

    dfs(dfs, 1);

    cout << ans.size() << nl;
    for (auto &[x, y] : ans) {
        cout << y.size() << " ";
        for (auto &z : y) {
            cout << z << " ";
        }
        cout << nl;
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