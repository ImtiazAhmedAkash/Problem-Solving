/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Built?

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
    int n;
    cin >> n;
    vector<pair<int, int>> X(n), Y(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        X[i] = {x, i};
        Y[i] = {y, i};
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    
    vector<array<int, 3>> G;
    for (int i = 1; i < n; i++) {
        int u = X[i - 1].second;
        int v = X[i].second;
        int w = X[i].first - X[i - 1].first;
        G.push_back({w, u, v});
    }
    for (int i = 1; i < n; i++) {
        int u = Y[i - 1].second;
        int v = Y[i].second;
        int w = Y[i].first - Y[i - 1].first;
        G.push_back({w, u, v});
    }
    
    sort(G.begin(), G.end());
    DSU dsu(n);
    ll ans = 0;
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
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}