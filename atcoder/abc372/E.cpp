/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// K-th Largest Connected Components

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

// Ordered Set
/*
 * s.find_by_order(k - 1);  // k-th biggest/smallest element in set
 * s.order_of_key(x);    // how many elements in set are less than x
 */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

struct DSU {
    vector<int> parent, Size;
    vector<ordered_set<int>> st;
    int components = 0;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        Size.assign(n + 1, 1);
        components = n;
        st.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            st[i].insert(i);
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;

        if (Size[x] < Size[y]) {
            swap(x, y);
        }
        Size[x] += Size[y];
        for (auto &i : st[y]) {
            st[x].insert(i);
        }
        parent[y] = x;
        components--;
        return true;
    }

    int size(int x) {
        return Size[find(x)];
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    DSU dsu(n);

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int u, v;
            cin >> u >> v;
            dsu.merge(u, v);
        } else {
            int v, k;
            cin >> v >> k;
            v = dsu.find(v);

            if (dsu.st[v].size() < k) {
                cout << -1 << nl;
            } else {
                cout << *(dsu.st[v].find_by_order(k - 1)) << nl;
            }
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