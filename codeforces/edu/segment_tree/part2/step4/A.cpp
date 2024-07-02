/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Assignment, Addition, and Sum

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

struct Data {
    int last;
    ll v;
    Data() {
        last = 0;
        v = 0;
    }
};

template <typename T>
struct LazySegmentTree {
    int n;
    vector<T> tree;
    vector<Data> lazy;
    LazySegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }
    void push(int node, int l, int r) {
        if (lazy[node].last == 1) {
            tree[node] = 1LL * (r - l + 1) * lazy[node].v;
            if (l != r) {
                lazy[2 * node].last = 1;
                lazy[2 * node].v = lazy[node].v;
                lazy[2 * node + 1].last = 1;
                lazy[2 * node + 1].v = lazy[node].v;
            }
            lazy[node].last = 0;
            lazy[node].v = 0;
        } else if (lazy[node].last == 2) {
            tree[node] += 1LL * (r - l + 1) * lazy[node].v;
            if (l != r) {
                if (lazy[2 * node].last != 1) {
                    lazy[2 * node].last = 2;
                }
                if (lazy[2 * node + 1].last != 1) {
                    lazy[2 * node + 1].last = 2;
                }
                lazy[2 * node].v += lazy[node].v;
                lazy[2 * node + 1].v += lazy[node].v;
            }
            lazy[node].last = 0;
            lazy[node].v = 0;
        }
    }
    void update(int node, int l, int r, int ql, int qr, int val, int type) {
        push(node, l, r);
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr) {
            lazy[node].last = type;
            lazy[node].v = val;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, val, type);
        update(2 * node + 1, mid + 1, r, ql, qr, val, type);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void update(int ql, int qr, int val, int type) {
        update(1, 1, n, ql, qr, val, type);
    }
    T query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
    }
    T query(int ql, int qr) {
        return query(1, 1, n, ql, qr);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    LazySegmentTree<ll> seg(n);

    while (q--) {
        int op, l, r, val;
        cin >> op >> l >> r;
        l++;
        if (op == 1) {
            cin >> val;
            seg.update(l, r, val, 1);
        } else if (op == 2) {
            cin >> val;
            seg.update(l, r, val, 2);
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