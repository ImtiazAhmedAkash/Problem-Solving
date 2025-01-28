/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// The Game (Easy Version)

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
    int cur;
    Data() {
        cur = 0;
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
        res.cur = A.cur + B.cur;
        return res;
    }
    void build(int node, int l, int r, const vector<int>& A) {
        if (l == r) {
            tree[node].cur = A[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, A);
        build(2 * node + 1, mid + 1, r, A);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int node, int l, int r, int indx, int val) {
        if (l == r) {
            tree[node].cur = val;
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
        if (qr < l || r < ql || ql > qr)
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
    vector<int> A(n + 1);
    vector id(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        id[A[i]].push_back(i);
    }
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    int timer = 0;
    vector<int> tin(n + 1), tout(n + 1);
    auto dfs = [&](auto&& self, int u, int par = -1) -> void {
        tin[u] = ++timer;
        for (auto &v : G[u]) {
            if (v == par) continue;
            self(self, v, u);
        }
        tout[u] = timer;
    };
    
    dfs(dfs, 1);
    
    SegmentTree seg(n);
    
    int maxCountSoFar = 0;
    for (int i = n; i > 0; i--) {
        if (id[i].empty()) continue;
        
        for (auto &node : id[i]) {
            int maxCountInSubtree = seg.query(tin[node], tout[node]).cur;
            if (maxCountInSubtree < maxCountSoFar) {
                cout << node << nl;
                return;
            }
        }
        maxCountSoFar += id[i].size();
        for (auto &node : id[i]) {
            seg.update(tin[node], 1);
        }
    }
    
    cout << 0 << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}