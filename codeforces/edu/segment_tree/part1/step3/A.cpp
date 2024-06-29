/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Inversions

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
    vector<int> tree;
    SegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n + 1);
    }
    void update(int node, int l, int r, int indx) {
        if (l == r) {
            tree[node] = 1;
            return;
        }
        int mid = (l + r) / 2;
        if (l <= indx && indx <= mid) {
            update(2 * node, l, mid, indx);
        } else {
            update(2 * node + 1, mid + 1, r, indx);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
    void update(int indx) {
        update(1, 1, n, indx);
    }
    int query(int node, int l, int r, int ql, int qr) {
        if (ql > qr || r < ql || qr < l)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        int left = query(2 * node, l, mid, ql, qr);
        int right = query(2 * node + 1, mid + 1, r, ql, qr);
        return left + right;
    }
    int query(int ql, int qr) {
        return query(1, 1, n, ql, qr);
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    SegmentTree seg(n);

    for (int i = 1; i <= n; i++) {
        cout << seg.query(A[i] + 1, n) << " \n"[i == n];
        seg.update(A[i]);
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