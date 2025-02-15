/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - Cables and Servers

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

struct DSU {
    vector<int> parent, Size;
    int components = 0;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        Size.assign(n + 1, 1);
        components = n;
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
        components--;
        return true;
    }
    int size(int x) {
        return Size[find(x)];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    
    DSU dsu(n);
    vector<array<int, 3>> options;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (dsu.same(u, v)) {
            options.push_back({i, u, v});
        }
        else {
            dsu.merge(u, v);
        }
    }
    
    set<int> leader;
    for (int i = 1; i <= n; i++) {
        if (dsu.find(i) == i) {
            leader.insert(i);
        }
    }
    
    vector<array<int, 3>> ans;
    while (dsu.components != 1) {
        auto [id, u, v] = options.back();
        options.pop_back();
        
        leader.erase(dsu.find(u));
        int w = *leader.begin();
        leader.erase(leader.begin());
        dsu.merge(u, w);
        leader.insert(dsu.find(u));
        ans.push_back({id, u, w});
    }
    
    cout << ans.size() << nl;
    for (auto &[id, u, v] : ans) {
        cout << id << " " << u << " " << v << nl;
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