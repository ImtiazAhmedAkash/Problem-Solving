/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Assignment and Maximal Segment

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 2e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

struct Data {
    ll pref, suff, sum, ans;
    Data() {
        pref = 0;
        suff = 0;
        sum = 0;
        ans = 0;
    }
};

template <typename T>
struct LazySegmentTree {
    int n;
    int default_lazy;
    vector<T> tree;
    vector<int> lazy;
    LazySegmentTree(int _n) {
        n = _n;
        default_lazy = inf;
        tree.resize(4 * n + 1);
        lazy.assign(4 * n + 1, default_lazy);
    }
    void push(int node, int l, int r) {
        if (lazy[node] == default_lazy)
            return;
        tree[node].sum = 1LL * (r - l + 1) * lazy[node];
        tree[node].pref = max(0LL, tree[node].sum);
        tree[node].suff = max(0LL, tree[node].sum);
        tree[node].ans = max(0LL, tree[node].sum);
        if (l != r) {
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        lazy[node] = default_lazy;
    }
    T merge(T& left, T& right) {
        T res;
        res.pref = max(left.pref, left.sum + right.pref);
        res.suff = max(right.suff, left.suff + right.sum);
        res.ans = max({left.ans, right.ans, left.suff + right.pref});
        res.sum = left.sum + right.sum;
        return res;
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
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int ql, int qr, int val) {
        update(1, 1, n, ql, qr, val);
    }
    T query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || r < ql)
            return T();
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        T left = query(2 * node, l, mid, ql, qr);
        T right = query(2 * node + 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }
    T query(int ql, int qr) {
        return query(1, 1, n, ql, qr);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    LazySegmentTree<Data> seg(n);

    while (q--) {
        int l, r, val;
        cin >> l >> r >> val;
        l++;
        seg.update(l, r, val);
        cout << seg.query(1, n).ans << nl;
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