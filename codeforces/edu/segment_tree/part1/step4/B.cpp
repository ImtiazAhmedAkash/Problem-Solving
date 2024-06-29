/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Cryptography

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int N = 2e5 + 5;

struct Data {
    int a, b, c, d;
    Data() {
        a = 1, b = 0, c = 0, d = 1;  // Identity Matrix (2 x 2)
    }
};

struct SegmentTree {
    int n, mod;
    vector<Data> tree;
    SegmentTree(int _n, int r) {
        n = _n;
        mod = r;
        tree.resize(4 * n + 1);
    }
    Data merge(Data& A, Data& B) {
        Data res;
        res.a = (A.a * B.a % mod + A.b * B.c % mod) % mod;
        res.b = (A.a * B.b % mod + A.b * B.d % mod) % mod;
        res.c = (A.c * B.a % mod + A.d * B.c % mod) % mod;
        res.d = (A.c * B.b % mod + A.d * B.d % mod) % mod;
        return res;
    }
    void build(int node, int l, int r, const vector<Data>& A) {
        if (l == r) {
            tree[node].a = A[l].a;
            tree[node].b = A[l].b;
            tree[node].c = A[l].c;
            tree[node].d = A[l].d;
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, A);
        build(2 * node + 1, mid + 1, r, A);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
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
    int r, n, m;
    cin >> r >> n >> m;

    vector<Data> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i].a >> A[i].b >> A[i].c >> A[i].d;
        A[i].a %= r;
        A[i].b %= r;
        A[i].c %= r;
        A[i].d %= r;
    }

    SegmentTree seg(n, r);
    seg.build(1, 1, n, A);

    while (m--) {
        int l, r;
        cin >> l >> r;
        Data ans = seg.query(l, r);
        cout << ans.a << " " << ans.b << nl;
        cout << ans.c << " " << ans.d << nl << nl;
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