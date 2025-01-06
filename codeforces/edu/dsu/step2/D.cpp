/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Bosses

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

struct DSU {
    vector<int> parent, Size, ans;
    int components = 0;
    DSU() {}
    DSU(int n) {
        init(n);
    }
    void init(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        Size.assign(n + 1, 1);
        ans.resize(n + 1, 0);
        components = n;
    }
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        int cur = find(parent[x]);
        ans[x] += ans[parent[x]];
        return parent[x] = cur;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    void merge(int x, int y) {
        parent[x] = y;
        ans[x] = 1;
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
            int a, b;
            cin >> a >> b;
            dsu.merge(a, b);
        } else {
            int c;
            cin >> c;
            dsu.find(c);
            cout << dsu.ans[c] << nl;
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