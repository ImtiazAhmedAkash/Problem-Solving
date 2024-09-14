/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Unicyclic Components

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
    vector<int> parent, Size, edges;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        Size.assign(n, 1);
        edges.assign(n, 0);
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
        edges[x] += edges[y] + 1;
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
        if (!dsu.merge(u, v)) {
            dsu.edges[dsu.find(u)]++;
        }
    }
    bool ok = true;
    for (int i = 1; i <= n; i++) {
        if (dsu.parent[i] != i) continue;
        if (dsu.Size[i] != dsu.edges[i]) ok = false;
    }
    cout << (ok ? "Yes" : "No") << nl;
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