/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Multiplication and Sum

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

template <typename T>
struct LazySegmentTree {
    int n;
    vector<T> tree, lazy;
    LazySegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n + 1);
        lazy.assign(4 * n + 1, 1);
    }
    void build(int node, int l, int r) {
        if (l == r) {
            tree[node] = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid);
        build(2 * node + 1, mid + 1, r);
        tree[node] = (0LL + tree[2 * node] + tree[2 * node + 1]) % mod;
    }
    void push(int node, int l, int r) {
        if (lazy[node] == 1)
            return;
        tree[node] = (1LL * tree[node] * lazy[node]) % mod;
        if (l != r) {
            lazy[2 * node] = (1LL * lazy[2 * node] * lazy[node]) % mod;
            lazy[2 * node + 1] = (1LL * lazy[2 * node + 1] * lazy[node]) % mod;
        }
        lazy[node] = 1;
    }
    void update(int node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr) {
            lazy[node] = val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, val);
        update(2 * node + 1, mid + 1, r, ql, qr, val);
        tree[node] = (0LL + tree[2 * node] + tree[2 * node + 1]) % mod;
    }
    void update(int ql, int qr, int val) {
        update(1, 1, n, ql, qr, val);
    }
    T query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        T left = query(2 * node, l, mid, ql, qr);
        T right = query(2 * node + 1, mid + 1, r, ql, qr);
        return (0LL + left + right) % mod;
    }
    T query(int ql, int qr) {
        return query(1, 1, n, ql, qr);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    LazySegmentTree<int> seg(n);
    seg.build(1, 1, n);

    while (q--) {
        int op, l, r, val;
        cin >> op >> l >> r;
        l++;
        if (op == 1) {
            cin >> val;
            seg.update(l, r, val);
        } else {
            cout << seg.query(l, r) << nl;
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