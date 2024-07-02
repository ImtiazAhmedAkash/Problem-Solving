/*  In the Name of ALLAH, the most gracious, the most merciful  */

// PRMQUER - Prime queries

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 2e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e7;

vector<bool> isPrime(N + 5, true);
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

struct Data {
    int cur, prime, lazy;
    bool need_lazy;
    Data() {
        cur = 0;
        prime = 0;
        lazy = 0;
        need_lazy = false;
    }
};

struct LazySegmentTree {
    int n;
    vector<Data> tree;
    LazySegmentTree(int _n) {
        n = _n;
        tree.resize(4 * n + 1);
    }
    void build(int node, int l, int r, const vector<int>& A) {
        if (l == r) {
            tree[node].cur = A[l];
            if (A[l] <= N && isPrime[A[l]]) {
                tree[node].prime = 1;
            }
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, A);
        build(2 * node + 1, mid + 1, r, A);
        tree[node].prime = tree[2 * node].prime + tree[2 * node + 1].prime;
    }
    void push(int node, int l, int r) {
        if (tree[node].need_lazy) {
            tree[node].cur = tree[node].lazy;
            if (tree[node].lazy <= N && isPrime[tree[node].lazy]) {
                tree[node].prime = r - l + 1;
            } else {
                tree[node].prime = 0;
            }
            if (l != r) {
                tree[2 * node].need_lazy = tree[2 * node + 1].need_lazy = true;
                tree[2 * node].lazy = tree[2 * node + 1].lazy = tree[node].lazy;
            }
            tree[node].need_lazy = false;
            tree[node].lazy = 0;
        }
    }
    void update(int node, int l, int r, int ql, int qr, int val, int type) {
        push(node, l, r);
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr) {
            // add
            if (type == 1) {
                tree[node].cur += val;
                if (tree[node].cur <= N && isPrime[tree[node].cur]) {
                    tree[node].prime = 1;
                } else {
                    tree[node].prime = 0;
                }
            }
            // replace
            else {
                tree[node].lazy = val;
                tree[node].need_lazy = true;
                push(node, l, r);
            }
            return;
        }
        int mid = (l + r) / 2;
        update(2 * node, l, mid, ql, qr, val, type);
        update(2 * node + 1, mid + 1, r, ql, qr, val, type);
        tree[node].prime = tree[2 * node].prime + tree[2 * node + 1].prime;
    }
    void update(int ql, int qr, int val, int type) {
        update(1, 1, n, ql, qr, val, type);
    }
    int query(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr < l || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node].prime;
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
    }
    int query(int ql, int qr) {
        return query(1, 1, n, ql, qr);
    }
};

void solve() {
    sieve();

    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    LazySegmentTree seg(n);
    seg.build(1, 1, n, A);

    while (q--) {
        char op;
        cin >> op;
        if (op == 'A') {
            int l, val;
            cin >> val >> l;
            seg.update(l, l, val, 1);
        } else if (op == 'R') {
            int a, l, r;
            cin >> a >> l >> r;
            seg.update(l, r, a, 2);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r) << nl;
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