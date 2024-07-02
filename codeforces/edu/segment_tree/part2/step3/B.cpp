/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Inverse and K-th one

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

template <typename T>
struct LazySegmentTree {
    int n;
    vector<T> tree, lazy;
    LazySegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }
    void push(int node, int l, int r) {
        if (lazy[node] == 0)
            return;
        tree[node] = (r - l + 1) - tree[node];
        if (l != r) {
            lazy[2 * node] ^= 1;
            lazy[2 * node + 1] ^= 1;
        }
        lazy[node] = 0;
    }
    void update(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr) {
            lazy[node] = 1;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr);
        update(2 * node + 1, mid + 1, r, ql, qr);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void update(int ql, int qr) {
        update(1, 1, n, ql, qr);
    }
    T query(int node, int l, int r, int k) {
        push(node, l, r);
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        push(2 * node, l, mid);
        if (tree[2 * node] >= k) {
            return query(2 * node, l, mid, k);
        }
        return query(2 * node + 1, mid + 1, r, k - tree[2 * node]);
    }
    T query(int k) {
        return query(1, 1, n, k);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    LazySegmentTree<int> seg(n);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r;
            cin >> l >> r;
            l++;
            seg.update(l, r);
        } else {
            int k;
            cin >> k;
            k++;
            cout << seg.query(k) - 1 << nl;
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