/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Road Construction

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
    vector<int> good(n + 1, 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        good[u] = good[v] = 0;
    }
    int src = 0;
    for (int i = 1; i <= n; i++) {
        if (good[i]) src = i;
    }
    cout << n - 1 << nl;
    for (int i = 1; i <= n; i++) {
        if (i != src) {
            cout << src << " " << i << nl;
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