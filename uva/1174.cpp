/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1174 - IP-TV

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

    int size(int x) {
        return Size[find(x)];
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    int id = 0;
    map<string, int> M;
    vector<array<int, 3>> G;
    while (m--) {
        string s, t;
        int w;
        cin >> s >> t >> w;
        if (M.find(s) == M.end()) {
            M[s] = id++;
        }
        if (M.find(t) == M.end()) {
            M[t] = id++;
        }
        int u = M[s];
        int v = M[t];
        G.push_back({w, u, v});
    }

    sort(G.begin(), G.end());
    DSU dsu(n);
    int ans = 0;
    for (int i = 0; i < G.size(); i++) {
        auto [w, u, v] = G[i];
        if (dsu.merge(u, v)) {
            ans += w;
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
        if (t < T) cout << nl;
    }

    return 0;
}