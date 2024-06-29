/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Number of Inversions on Segment

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
    ll ans;
    vector<int> cnt;
    Data() {
        ans = 0;
        cnt.resize(N + 1);
    }
};

struct SegmentTree {
    int n;
    vector<Data> tree;
    SegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n);
    }
    Data merge(Data& A, Data& B) {
        Data res;
        int sum = 0;
        res.ans = A.ans + B.ans;
        for (int i = N; i > 0; i--) {
            res.cnt[i] = A.cnt[i] + B.cnt[i];
            res.ans += 1LL * B.cnt[i] * sum;
            sum += A.cnt[i];
        }
        return res;
    }
    void build(int node, int l, int r, const vector<int>& A) {
        if (l == r) {
            tree[node].cnt[A[l]] = 1;
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
            tree[node].ans = 0;
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