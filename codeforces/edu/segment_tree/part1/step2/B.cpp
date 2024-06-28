/*  In the Name of ALLAH, the most gracious, the most merciful  */

// K-th one

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
        tree.resize(4 * n);
    }
    void build(int node, int l, int r, const vector<int>& A) {
        if (l == r) {
            tree[node] = A[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid, A);
        build(2 * node + 2, mid + 1, r, A);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    void update(int node, int l, int r, int indx) {
        if (l == r) {
            tree[node] ^= 1;
            return;
        }
        int mid = (l + r) / 2;
        if (l <= indx && indx <= mid) {
            update(2 * node + 1, l, mid, indx);
        } else {
            update(2 * node + 2, mid + 1, r, indx);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
    void update(int indx) {
        update(0, 0, n - 1, indx);
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (r < ql || qr < l) return 0;
        if (ql <= l && r <= qr) return tree[node];
        int mid = (l + r) / 2;
        int left = query(2 * node + 1, l, mid, ql, qr);
        int right = query(2 * node + 2, mid + 1, r, ql, qr);
        return left + right;
    }
    int query(int ql, int qr) {
        return query(0, 0, n - 1, ql, qr);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    SegmentTree seg(n);
    seg.build(0, 0, n - 1, A);

    while (q--) {
        int op, x;
        cin >> op >> x;
        if (op == 1) {
            seg.update(x);
            continue;
        }

        int L = 0, R = n;
        while (L < R) {
            int M = L + (R - L) / 2;
            if (seg.query(0, M) >= x + 1) {
                R = M;
            } else {
                L = M + 1;
            }
        }
        cout << L << nl;
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