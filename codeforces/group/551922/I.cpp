/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Not Too Hot, Not Too Cold

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

// 1-based indexing
struct SegmentTree {
    int n;
    vector<int> tree;
    SegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n + 1);
    }
    void build(int node, int l, int r, const vector<int>& A) {
        if (l == r) {
            tree[node] = A[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, A);
        build(2 * node + 1, mid + 1, r, A);
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
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
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int indx, int val) {
        update(1, 1, n, indx, val);
    }
    int query(int node, int l, int r, int ql, int qr, int val) {
        if (tree[node] <= val) {
            return -1;
        }
        if (r < ql || qr < l) {
            return -1;
        }
        if (l == r) {
            return l;
        }
        int mid = (l + r) / 2;
        int left = query(2 * node, l, mid, ql, qr, val);
        if (left != -1) {
            return left;
        }
        return query(2 * node + 1, mid + 1, r, ql, qr, val);
    }
    int query(int ql, int val) {
        return query(1, 1, n, ql, n, val);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<int> diff(n + 1);
    for (int i = 2; i <= n; i++) {
        diff[i] = abs(A[i] - A[i - 1]);
    }

    SegmentTree seg(n);
    seg.build(1, 1, n, diff);

    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int i, p;
            cin >> i >> p;
            A[i] = p;
            if (i != 1) {
                diff[i] = abs(A[i] - A[i - 1]);
                seg.update(i, diff[i]);
            }
            if (i != n) {
                diff[i + 1] = abs(A[i] - A[i + 1]);
                seg.update(i + 1, diff[i + 1]);
            }
        } else {
            int i, t;
            cin >> i >> t;
            int ans = seg.query(i + 1, t);
            if (ans == -1) {
                ans = n;
            } else {
                ans--;
            }
            cout << ans << nl;
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