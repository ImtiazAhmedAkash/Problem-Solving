/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Number of Minimums on a Segment

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 2e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

struct Info {
    int mini, cnt;
    Info() {
        mini = inf;
        cnt = 1;
    }
};

struct SegmentTree {
    int n;
    vector<Info> tree;
    SegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n);
    }
    Info merge(Info a, Info b) {
        Info res;
        if (a.mini < b.mini) {
            res = a;
        } else if (a.mini > b.mini) {
            res = b;
        } else {
            res.mini = a.mini;
            res.cnt = a.cnt + b.cnt;
        }
        return res;
    }
    void build(int node, int l, int r, const vector<int>& A) {
        if (l == r) {
            tree[node].mini = A[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid, A);
        build(2 * node + 2, mid + 1, r, A);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
    void update(int node, int l, int r, int indx, int val) {
        if (l == r) {
            tree[node].mini = val;
            tree[node].cnt = 1;
            return;
        }
        int mid = (l + r) / 2;
        if (l <= indx && indx <= mid) {
            update(2 * node + 1, l, mid, indx, val);
        } else {
            update(2 * node + 2, mid + 1, r, indx, val);
        }
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
    void update(int indx, int val) {
        update(0, 0, n - 1, indx, val);
    }
    Info query(int node, int l, int r, int ql, int qr) {
        if (r < ql || qr < l)
            return Info();
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        Info left = query(2 * node + 1, l, mid, ql, qr);
        Info right = query(2 * node + 2, mid + 1, r, ql, qr);
        return merge(left, right);
    }
    Info query(int ql, int qr) {
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
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            seg.update(x, y);
        } else {
            Info ans = seg.query(x, y - 1);
            cout << ans.mini << " " << ans.cnt << nl;
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