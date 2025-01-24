/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Subarray Sum Queries

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
    ll left, right, total, ans;
    Data() {
        left = right = total = ans = 0;
    }
};

// 1-based indexing
struct SegmentTree {
    int n;
    vector<Data> tree;
    SegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n + 1);
    }
    Data merge(const Data& A, const Data& B) {
        Data res;
        res.left = max(A.left, A.total + B.left);
        res.right = max(B.right, A.right + B.total);
        res.total = A.total + B.total;
        res.ans = max({A.ans, B.ans, A.right + B.left});
        return res;
    }
    void build(int node, int l, int r, const vector<int>& A) {
        if (l == r) {
            tree[node].left = A[l];
            tree[node].right = A[l];
            tree[node].total = A[l];
            tree[node].ans = A[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, A);
        build(2 * node + 1, mid + 1, r, A);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int node, int l, int r, int indx, int val) {
        if (l == r) {
            tree[node].left = val;
            tree[node].right = val;
            tree[node].total = val;
            tree[node].ans = val;
            return;
        }
        int mid = (l + r) / 2;
        if (l <= indx && indx <= mid) {
            update(2 * node, l, mid, indx, val);
        } else {
            update(2 * node + 1, mid + 1, r, indx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int indx, int val) {
        update(1, 1, n, indx, val);
    }
    Data query(int node, int l, int r, int ql, int qr) {
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
    
    SegmentTree seg(n);
    seg.build(1, 1, n, A);
    
    while (q--) {
        int k, x;
        cin >> k >> x;
        seg.update(k, x);
        cout << max(0LL, seg.query(1, n).ans) << nl;
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