/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Christmas Spruce

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
    cin >> n;
    vector<int> G[n + 1];
    for (int v = 2; v <= n; v++) {
        int u;
        cin >> u;
        G[u].push_back(v);
    }
    vector<int> child(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        child[i] = G[i].size();
    }

    bool ok = true;
    auto bfs = [&](int src) {
        queue<int> Q;
        Q.push(src);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto v : G[u]) {
                if (child[v]) {
                    child[u]--;
                    if (child[u] == 0) ok = false;
                }
                Q.push(v);
            }
        }
    };

    bfs(1);
    ok &= all_of(child.begin(), child.end(), [&](int i) { return i == 0 || i >= 3; });
    cout << (ok ? "Yes" : "No") << nl;
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