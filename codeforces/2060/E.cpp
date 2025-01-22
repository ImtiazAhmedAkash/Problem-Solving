/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Graph Composition

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
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vector<pair<int, int>> F(m1);
    for (auto &[x, y] : F) {
        cin >> x >> y;
    }
    
    DSU dsuG(n);
    for (int i = 0; i < m2; i++) {
        int u, v;
        cin >> u >> v;
        dsuG.merge(u, v);
    }
    
    int ans = 0;
    DSU dsuF(n);
    
    for (auto &[x, y] : F) {
        if (dsuG.same(x, y)) {
            dsuF.merge(x, y);
        } else {
            ans++;
        }
    }
    
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        int parG = dsuG.find(i);
        mp[parG].push_back(i);
    }
    
    for (auto &[parG, v] : mp) {
        for (auto &x : v) {
            if (!dsuF.same(parG, x)) {
                dsuF.merge(parG, x);
                ans++;
            }
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
    }
    
    return 0;
}