/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Gifts Order

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

struct Data {
    ll minL, minR, maxL, maxR, ans;
    Data() {
        minL = minR = INF;
        maxL = maxR = -INF;
        ans = 0;
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
        res.minL = min(A.minL, B.minL);
        res.minR = min(A.minR, B.minR);
        res.maxL = max(A.maxL, B.maxL);
        res.maxR = max(A.maxR, B.maxR);
        res.ans = max({A.ans, B.ans, B.maxR - A.minL, A.maxL - B.minR});
        return res;
    }
    void build(int node, int l, int r, const vector<int>& A) {
        if (l == r) {
            tree[node].maxR = A[l] - l;
            tree[node].minL = A[l] - l;
            tree[node].maxL = A[l] + l;
            tree[node].minR = A[l] + l;
            tree[node].ans = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, A);
        build(2 * node + 1, mid + 1, r, A);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int node, int l, int r, int indx, int val) {
        if (l == r) {
            tree[node].maxR = val - l;
            tree[node].minL = val - l;
            tree[node].maxL = val + l;
            tree[node].minR = val + l;
            tree[node].ans = 0;
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
    
    cout << seg.query(1, n).ans << nl;
    
    while (q--) {
        int p, x;
        cin >> p >> x;
        seg.update(p, x);
        cout << seg.query(1, n).ans << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}