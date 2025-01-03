/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Road Construction

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
    int components = 0;
    int mx = 1;
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
        mx = max(mx, Size[x]);
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
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.merge(u, v);
        cout << dsu.components << " " << dsu.mx << nl;
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