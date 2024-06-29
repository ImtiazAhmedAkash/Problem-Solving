/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sign alternation

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

struct SegmentTree {
    int n;
    vector<int> tree;
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
    void update(int node, int l, int r, int indx, int val) {
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
    void update(int indx, int val) {
        update(1, 1, n, indx, val);
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
    }
    int query(int ql, int qr) {
        return query(1, 1, n, ql, qr);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (i % 2 == 0) {
            A[i] *= -1;
        }
    }

    SegmentTree seg(n);
    seg.build(1, 1, n, A);

    int q;
    cin >> q;
    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 0) {
            if (x % 2 == 0) {
                y *= -1;
            }
            seg.update(x, y);
        } else {
            int ans = seg.query(x, y);
            cout << (x % 2 == 0 ? -ans : ans) << nl;
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