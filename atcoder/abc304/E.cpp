/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Good Graph

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

struct DSU {
    vector<int> parent, Size;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        Size.assign(n, 1);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (Size[x] < Size[y]) swap(x, y);
        Size[x] += Size[y];
        parent[y] = x;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        dsu.merge(u, v);
    }

    int k;
    cin >> k;
    set<pair<int, int>> banned;
    while (k--) {
        int u, v;
        cin >> u >> v;
        u = dsu.find(u);
        v = dsu.find(v);
        if (u > v) swap(u, v);
        banned.insert({u, v});
    }

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        u = dsu.find(u);
        v = dsu.find(v);
        if (u > v) swap(u, v);
        cout << (banned.find(make_pair(u, v)) == banned.end() ? "Yes" : "No") << nl;
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