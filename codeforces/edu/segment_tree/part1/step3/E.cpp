/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Addition to Segment

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
    vector<ll> tree;
    SegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n);
    }
    void update(int node, int l, int r, int indx, int val) {
        if (l == r) {
            tree[node] += val;
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
    ll query(int node, int l, int r, int ql, int qr) {
        if (r < ql || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        ll left = query(2 * node, l, mid, ql, qr);
        ll right = query(2 * node + 1, mid + 1, r, ql, qr);
        return left + right;
    }
    ll query(int ql, int qr) {
        return query(1, 1, n, ql, qr);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    SegmentTree seg(n + 1);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            l++, r++;
            seg.update(l, v);
            if (r <= n)
                seg.update(r, -v);
        } else {
            int x;
            cin >> x;
            cout << seg.query(1, x + 1) << nl;
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