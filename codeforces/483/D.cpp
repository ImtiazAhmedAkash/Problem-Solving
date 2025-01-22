/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Interesting Array

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
    int merge(int A, int B) {
        return (A & B);
    }
    void build(int node, int l, int r, const vector<int>& A) {
        if (l == r) {
            tree[node] = A[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, A);
        build(2 * node + 1, mid + 1, r, A);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
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
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int indx, int val) {
        update(1, 1, n, indx, val);
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql)
            return (1 << 30) - 1;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        int left = query(2 * node, l, mid, ql, qr);
        int right = query(2 * node + 1, mid + 1, r, ql, qr);
        return merge(left, right);
    }
    int query(int ql, int qr) {
        return query(1, 1, n, ql, qr);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vector<array<int, 3>> A(q);
    vector B(n + 5, vector<int>(35));
    for (int i = 0; i < q; i++) {
        int l, r, v;
        cin >> l >> r >> v;
        A[i] = {l, r, v};
        for (int bit = 0; bit < 30; bit++) {
            if ((v >> bit) & 1) {
                B[l][bit]++;
                B[r + 1][bit]--;
            }
        }
    }

    for (int bit = 0; bit < 30; bit++) {
        for (int i = 1; i <= n; i++) {
            B[i][bit] += B[i - 1][bit];
        }
    }

    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int bit = 0; bit < 30; bit++) {
            if (B[i][bit]) {
                ans[i] |= (1 << bit);
            }
        }
    }

    SegmentTree seg(n);
    seg.build(1, 1, n, ans);

    for (int i = 0; i < q; i++) {
        auto [l, r, v] = A[i];
        if (seg.query(l, r) != v) {
            cout << "NO" << nl;
            return;
        }
    }

    cout << "YES" << nl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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