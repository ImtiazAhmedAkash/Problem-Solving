/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Rated Range

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 5e5;

struct Data {
    int mini, maxi, lazy;
    bool need_lazy;
    Data() {
        mini = inf;
        maxi = 0;
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
        res.mini = min(A.mini, B.mini);
        res.maxi = max(A.maxi, B.maxi);
        return res;
    }
    void push(int node, int l, int r) {
        if (tree[node].need_lazy) {
            tree[node].mini += tree[node].lazy;
            tree[node].maxi += tree[node].lazy;
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
            tree[node].mini = A[l];
            tree[node].maxi = A[l];
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
    int find_min_indx(int node, int l, int r, int val) {
        push(node, l, r);
        if (tree[node].maxi < val) {
            return n + 1;
        }
        if (l == r) {
            return l;
        }
        int mid = (l + r) / 2;
        int left = find_min_indx(2 * node, l, mid, val);
        if (left == n + 1) {
            left = find_min_indx(2 * node + 1, mid + 1, r, val);
        }
        return left;
    }
    int find_min_indx(int val) {
        return find_min_indx(1, 1, n, val);
    }
    int find_max_indx(int node, int l, int r, int val) {
        push(node, l, r);
        if (tree[node].mini > val) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int mid = (l + r) / 2;
        int right = find_max_indx(2 * node + 1, mid + 1, r, val);
        if (right == -1) {
            right = find_max_indx(2 * node, l, mid, val);
        }
        return right;
    }
    int find_max_indx(int val) {
        return find_max_indx(1, 1, n, val);
    }
};

void solve() {
    vector<int> A(N + 1);
    iota(A.begin(), A.end(), 0);

    LazySegmentTree seg(N);
    seg.build(1, 1, N, A);

    int n;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        x = seg.find_min_indx(x);
        y = seg.find_max_indx(y);
        if (x <= y) {
            seg.update(x, y, 1);
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        cout << seg.query(x, x).mini << nl;
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