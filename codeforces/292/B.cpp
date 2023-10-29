/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Network Topology

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> deg(n + 1, 0);
    while (m--) {
        int u, v;
        cin >> u >> v;
        deg[u]++, deg[v]++;
    }
    map<int, int> M;
    for (int i = 1; i <= n; i++) {
        M[deg[i]]++;
    }
    string ans = "unknown";
    if (M[2] == n) ans = "ring";
    else if (M[1] == 2 && M[2] == n - 2) ans = "bus";
    else if (M[1] == n - 1) ans = "star";
    cout << ans << " topology" << nl;
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