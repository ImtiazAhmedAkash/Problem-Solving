/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Lunar New Year and a Wander

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
    vector<int> G[n + 1];
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<bool> used(n + 1, false);
    vector<int> ans;

    auto bfs = [&](int src) {
        priority_queue<int, vector<int>, greater<int>> PQ;
        PQ.push(src);
        used[src] = true;
        while (!PQ.empty()) {
            int u = PQ.top();
            PQ.pop();
            ans.push_back(u);
            for (auto v : G[u]) {
                if (!used[v]) {
                    PQ.push(v);
                    used[v] = true;
                }
            }
        }
    };

    bfs(1);
    for (auto x : ans) cout << x << " ";
    cout << nl;
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