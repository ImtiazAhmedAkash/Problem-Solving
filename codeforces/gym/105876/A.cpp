/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// A - Among the Tall

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b /= 2;
    }
    return ans;
}
int inverseMod(int a) {
    return power(a, mod - 2);
}

struct Data {
    ll sum;
    int cnt;
    Data() {
        sum = 0;
        cnt = 0;
    }
};

// 1-based indexing
struct SegmentTree {
    int n;
    vector<Data> tree;
    SegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n + 1);
    }
    Data merge(const Data& A, const Data& B) {
        Data res;
        res.sum = (A.sum + B.sum) % mod;
        res.cnt = A.cnt + B.cnt;
        return res;
    }
    void update(int node, int l, int r, int indx, int val) {
        if (l == r) {
            tree[node].sum = val;
            tree[node].cnt = 1;
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
    int n;
    cin >> n;
    vector<pair<ll, int>> A(n + 1);
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        A[i] = {x, i};
    }
    
    sort(A.begin() + 1, A.end(), [&](pair<ll, int>& x, pair<ll, int>& y) {
        if (x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    });
    
    SegmentTree seg(n);
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        seg.update(A[i].second, A[i].first % mod);
        Data res = seg.query(1, A[i].second);
        ans[A[i].second] = 1LL * res.sum * inverseMod(res.cnt) % mod;
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