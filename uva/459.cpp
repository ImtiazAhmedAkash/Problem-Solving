/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 459 - Graph Connectivity

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
    string x;
    cin >> x;
    cin.ignore();
    int n = x.front() - 'A';
    vector<vector<int>> G(n + 1, vector<int>());

    string s;
    while (getline(cin, s) && !s.empty()) {
        int u = s.front() - 'A';
        int v = s.back() - 'A';
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<bool> used(n + 1, false);
    auto bfs = [&](int src) -> void {
        queue<int> Q;
        Q.push(src);
        used[src] = true;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto v : G[u]) {
                if (!used[v]) {
                    used[v] = true;
                    Q.push(v);
                }
            }
        }
    };

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (!used[i]) {
            bfs(i);
            ans++;
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
        if (t < T) cout << nl;
    }

    return 0;
}