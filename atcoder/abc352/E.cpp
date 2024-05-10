/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Clique Connect

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
        components = n - 1;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
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
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> G;
    while (m--) {
        int k, w;
        cin >> k >> w;
        vector<int> A(k);
        for (auto& x : A) cin >> x;
        for (int i = 1; i < k; i++) {
            G.push_back({w, A[0], A[i]});
        }
    }
    sort(G.begin(), G.end());

    DSU dsu(n + 1);
    ll ans = 0;
    for (int i = 0; i < G.size(); i++) {
        auto [w, u, v] = G[i];
        if (dsu.merge(u, v)) {
            ans += w;
        }
    }

    cout << (dsu.components == 1 ? ans : -1) << nl;
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