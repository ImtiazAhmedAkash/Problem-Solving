/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Earthquakes

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 2e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

struct SegmentTree {
    int n;
    vector<int> tree;
    SegmentTree(int _n) {
        n = _n;
        tree.assign(4 * n + 1, inf);
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
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int indx, int val) {
        update(1, 1, n, indx, val);
    }
    int query(int node, int l, int r, int ql, int qr, int lim) {
        if (tree[node] > lim || qr < l || r < ql)
            return 0;
        if (l == r) {
            tree[node] = inf;
            return 1;
        }
        int mid = (l + r) / 2;
        int left = query(2 * node, l, mid, ql, qr, lim);
        int right = query(2 * node + 1, mid + 1, r, ql, qr, lim);
        tree[node] = min(tree[2 * node], tree[2 * node + 1]);
        return left + right;
    }
    int query(int ql, int qr, int lim) {
        return query(1, 1, n, ql, qr, lim);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    SegmentTree seg(n);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            x++;
            seg.update(x, y);
        } else {
            int l, r, p;
            cin >> l >> r >> p;
            l++;
            cout << seg.query(l, r, p) << nl;
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