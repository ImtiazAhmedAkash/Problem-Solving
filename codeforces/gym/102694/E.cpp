/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Filthy Rich Trees

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

// 1-based indexing
template <typename T>
struct SegmentTree {
    int n;
    vector<T> tree;
    SegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n + 1);
    }
    void build(int node, int l, int r, const vector<int>& A) {
        if (l == r) {
            tree[node] = A[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, A);
        build(2 * node + 1, mid + 1, r, A);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void update(int node, int l, int r, int indx, T val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (l <= indx && indx <= mid) {
            update(2 * node, l, mid, indx, val);
        } else {
            update(2 * node + 1, mid + 1, r, indx, val);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void update(int indx, T val) {
        update(1, 1, n, indx, val);
    }
    T query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return 0.0;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        T left = query(2 * node, l, mid, ql, qr);
        T right = query(2 * node + 1, mid + 1, r, ql, qr);
        return left + right;
    }
    T query(int ql, int qr) {
        return query(1, 1, n, ql, qr);
    }
};

void solve() {
    int n;
    cin >> n;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> tin(n + 1), tout(n + 1);
    int timer = 0;
    auto dfs = [&](auto&& self, int u, int par = 0) -> void {
        tin[u] = ++timer;
        for (auto& v : G[u]) {
            if (v == par) continue;
            self(self, v, u);
        }
        tout[u] = timer;
    };

    dfs(dfs, 1);
    SegmentTree<double> seg(n);

    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            seg.update(tin[x], log10(y));
        } else {
            int x, y;
            cin >> x >> y;
            double up = seg.query(tin[x], tout[x]);
            double down = seg.query(tin[y], tout[y]);
            if (up - down < 9) {
                cout << fixed << setprecision(10) << pow(10, up - down) << nl;
            } else {
                cout << 1000000000 << nl;
            }
        }
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