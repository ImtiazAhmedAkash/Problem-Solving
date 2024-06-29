/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Inversions 2

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
    // returns the index of k-th zero from the last (1-based indexing)
    int query(int node, int l, int r, int k) {
        if (l == r)
            return l;
        int mid = (l + r) / 2;
        int zero = r - mid - tree[2 * node + 1];
        if (k <= zero)
            return query(2 * node + 1, mid + 1, r, k);
        return query(2 * node, l, mid, k - zero);
    }
    int query(int k) {
        return query(1, 1, n, k);
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
    vector<int> ans(n + 1);

    for (int i = n; i > 0; i--) {
        ans[i] = seg.query(A[i] + 1);
        seg.update(ans[i]);
    }

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