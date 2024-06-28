/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Segment with the Maximum Sum

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

struct Data {
    ll pref, suff, sum, max_sum;
    Data() {
        pref = 0;
        suff = 0;
        sum = 0;
        max_sum = 0;
    }
};

struct SegmentTree {
    int n;
    vector<Data> tree;
    SegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n);
    }
    Data merge(Data left, Data right) {
        Data res;
        res.pref = max(left.pref, left.sum + right.pref);
        res.suff = max(right.suff, left.suff + right.sum);
        res.sum = left.sum + right.sum;
        res.max_sum = max({left.max_sum, right.max_sum, left.suff + right.pref});
        return res;
    }
    void build(int node, int l, int r, const vector<int>& A) {
        if (l == r) {
            tree[node].pref = A[l];
            tree[node].suff = A[l];
            tree[node].sum = A[l];
            tree[node].max_sum = A[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node + 1, l, mid, A);
        build(2 * node + 2, mid + 1, r, A);
        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }
    void update(int node, int l, int r, int indx, int val) {
        if (l == r) {
            tree[node].pref = val;
            tree[node].suff = val;
            tree[node].sum = val;
            tree[node].max_sum = val;
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
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (auto& x : A) cin >> x;
    
    SegmentTree seg(n);
    seg.build(0, 0, n - 1, A);
    
    cout << max(0LL, seg.tree[0].max_sum) << nl;
    
    while (q--) {
        int x, y;
        cin >> x >> y;
        seg.update(x, y);
        cout << max(0LL, seg.tree[0].max_sum) << nl;
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