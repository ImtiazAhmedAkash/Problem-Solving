/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Sum of Max Matching

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
    vector<int> A, B;
    int components = 0;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        Size.assign(n + 1, 1);
        A.resize(n + 1);
        B.resize(n + 1);
        components = n;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    ll merge(int x, int y, int wt) {
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        
        ll ans = 0;
        int cur = min(A[x], B[y]);
        ans += 1LL * cur * wt;
        A[x] -= cur;
        B[y] -= cur;
        
        cur = min(A[y], B[x]);
        ans += 1LL * cur * wt;
        A[y] -= cur;
        B[x] -= cur;

        if (Size[x] < Size[y]) swap(x, y);
        Size[x] += Size[y];
        parent[y] = x;
        A[x] += A[y];
        B[x] += B[y];
        components--;
        return ans;
    }

    int size(int x) {
        return Size[find(x)];
    }
};

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    DSU dsu(n);
    vector<array<int, 3>> G(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[i] = {w, u, v};
    }
    
    sort(G.begin(), G.end());
    
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        dsu.A[x]++;
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        dsu.B[x]++;
    }
    
    ll ans = 0;
    for (auto &[w, u, v] : G) {
        ans += dsu.merge(u, v, w);
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