/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1040 - Donation

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

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        Size.assign(n, 1);
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
    int n;
    cin >> n;
    int total = 0, x = 0;
    vector<array<int, 3>> G;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            total += x;
            if (i != j && x) {
                G.push_back({x, i, j});
            }
        }
    }

    // Minimum Spanning Tree
    sort(G.begin(), G.end());
    DSU dsu(n);
    int need = 0;
    for (int i = 0; i < G.size(); i++) {
        auto [w, u, v] = G[i];
        if (dsu.merge(u, v)) {
            need += w;
        }
    }
    cout << (dsu.components == 1 ? total - need : -1) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}