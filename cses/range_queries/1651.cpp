/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Range Update Queries

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
    ll cur, lazy;
    bool need_lazy;
    Data() {
        cur = 0;
        lazy = 0;
        need_lazy = false;
    }
};

// 1-based indexing
struct LazySegmentTree {
    int n;
    vector<Data> tree;
    LazySegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n + 1);
    }
    Data merge(const Data& A, const Data& B) {
        Data res;
        res.cur = A.cur + B.cur;
        return res;
    }
    void push(int node, int l, int r) {
        if (tree[node].need_lazy) {
            tree[node].cur += 1LL * (r - l + 1) * tree[node].lazy;
            if (l != r) {
                tree[2 * node].need_lazy = tree[2 * node + 1].need_lazy = true;
                tree[2 * node].lazy += tree[node].lazy;
                tree[2 * node + 1].lazy += tree[node].lazy;
            }
            tree[node].need_lazy = false;
            tree[node].lazy = 0;
        }
    }
    void build(int node, int l, int r, const vector<int>& A) {
        if (l == r) {
            tree[node].cur = A[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, A);
        build(2 * node + 1, mid + 1, r, A);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int node, int l, int r, int ql, int qr, int val) {
        push(node, l, r);
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr) {
            tree[node].lazy += val;
            tree[node].need_lazy = true;
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
    Data query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || r < ql)
            return Data();
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        Data left = query(2 * node, l, mid, ql, qr);
        Data right = query(2 * node + 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }
    Data query(int ql, int qr) {
        return query(1, 1, n, ql, qr);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    LazySegmentTree seg(n);
    seg.build(1, 1, n, A);
    
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b, u;
            cin >> a >> b >> u;
            seg.update(a, b, u);
        }
        else {
            int k;
            cin >> k;
            cout << seg.query(k, k).cur << nl;
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