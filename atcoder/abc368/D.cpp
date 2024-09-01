/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Minimum Steiner Tree

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
    int n, k;
    cin >> n >> k;

    vector G(n + 1, vector<int>());
    vector<int> degree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }

    vector<bool> good(n + 1);
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        good[x] = true;
    }

    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1 && !good[i]) {
            Q.push(i);
        }
    }

    int ans = n;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        ans--;
        for (auto v : G[u]) {
            degree[v]--;
            if (degree[v] == 1 && !good[v]) {
                Q.push(v);
            }
        }
    }
    cout << ans << nl;
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