/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bicoloring

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
    int n;
    while (cin >> n && n) {
        vector<int> G[n];
        int l;
        cin >> l;
        while (l--) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vector<int> color(n, -1);
        bool ok = true;
        queue<int> Q;
        Q.push(0);
        color[0] = 1;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto v : G[u]) {
                if (color[v] == -1) {
                    color[v] = !color[u];
                    Q.push(v);
                    continue;
                }
                if (color[v] == color[u]) ok = false;
            }
        }
        cout << (ok ? "BICOLORABLE." : "NOT BICOLORABLE.") << nl;
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