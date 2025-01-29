/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Forever Winter

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector G(n + 1, vector<int>());
    vector<int> degree(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        degree[u]++, degree[v]++;
    }
    
    int leaf = 0;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) {
            leaf = i;
        }
    }
    int leafParent = G[leaf].front();
    int centralNode = 0;
    for (auto &v : G[leafParent]) {
        if (degree[v] != 1) {
            centralNode = v;
        }
    }
    
    int x = degree[centralNode];
    int y = degree[leafParent] - 1;
    
    cout << x << " " << y << nl;
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