/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Number of Different on Segment

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 40;

struct Data {
    int ans;
    int cnt[N + 1];
    Data() {
        ans = 0;
        memset(cnt, 0, sizeof(cnt));
    }
};

template <typename T>
struct SegmentTree {
    int n;
    vector<T> tree;
    SegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n + 1);
    }
    T merge(const T& A, const T& B) {
        T res;
        for (int i = 1; i <= N; i++) {
            res.cnt[i] = A.cnt[i] + B.cnt[i];
            if (res.cnt[i]) {
                res.ans++;
            }
        }
        return res;
    }
    void build(int node, int l, int r, const vector<int>& A) {
        if (l == r) {
            tree[node].cnt[A[l]] = 1;
            tree[node].ans = 1;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, A);
        build(2 * node + 1, mid + 1, r, A);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int node, int l, int r, int indx, int prev, int val) {
        if (l == r) {
            tree[node].cnt[prev] = 0;
            tree[node].cnt[val] = 1;
            tree[node].ans = 1;
            return;
        }
        int mid = (l + r) / 2;
        if (l <= indx && indx <= mid) {
            update(2 * node, l, mid, indx, prev, val);
        } else {
            update(2 * node + 1, mid + 1, r, indx, prev, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int indx, int prev, int val) {
        update(1, 1, n, indx, prev, val);
    }
    T query(int node, int l, int r, int ql, int qr) {
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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    SegmentTree<Data> seg(n);
    seg.build(1, 1, n, A);

    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            cout << seg.query(x, y).ans << nl;
        } else {
            seg.update(x, A[x], y);
            A[x] = y;
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