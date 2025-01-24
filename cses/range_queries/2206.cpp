/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Pizzeria Queries

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
    int sum;   // P[i] + i
    int diff;  // P[i] - i
    Data() {
        sum = inf;
        diff = inf;
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
        res.sum = min(A.sum, B.sum);
        res.diff = min(A.diff, B.diff);
        return res;
    }
    void build(int node, int l, int r, const vector<int>& A) {
        if (l == r) {
            tree[node].sum = A[l] + l;
            tree[node].diff = A[l] - l;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, A);
        build(2 * node + 1, mid + 1, r, A);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int node, int l, int r, int indx, int val) {
        if (l == r) {
            tree[node].sum = val + l;
            tree[node].diff = val - l;
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
        int op;
        cin >> op;
        if (op == 1) {
            int k, x;
            cin >> k >> x;
            seg.update(k, x);
        }
        else {
            int k;
            cin >> k;
            int right = seg.query(k, n).sum - k; // P[k] + k = P[a] + a (when k <= a)
            int left = seg.query(1, k).diff + k; // P[k] - k = P[a] - a (when k >= a)
            cout << min(left, right) << nl;
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