/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1208 - Oreon

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
    vector<int> parent, Size;

    DSU() {}
    DSU(int n) {
        init(n);
    }

    void init(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        Size.assign(n, 1);
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

        if (Size[x] < Size[y]) swap(x, y);
        Size[x] += Size[y];
        parent[y] = x;
        return true;
    }

    int size(int x) {
        return Size[find(x)];
    }
};

void solve() {
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<int>> A(n, vector<int>());
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ',') s[i] = ' ';
        }
        stringstream ss(s);
        int x;
        while (ss >> x) {
            A[i].push_back(x);
        }
    }

    vector<array<int, 3>> G;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i][j] == 0) continue;
            G.push_back({A[i][j], i, j});
        }
    }

    sort(G.begin(), G.end());
    DSU dsu(n);
    for (int i = 0; i < G.size(); i++) {
        auto [w, u, v] = G[i];
        if (dsu.merge(u, v)) {
            cout << (char)('A' + u) << "-" << (char)('A' + v) << " " << w << nl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ":" << nl;
        solve();
    }

    return 0;
}