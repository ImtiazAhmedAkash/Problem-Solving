/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Longest Path

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
    vector<int> indegree(n + 1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        indegree[v]++;
    }

    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            Q.push(i);
        }
    }

    vector<int> dp(n + 1);
    //  dp[i] = length of the longest path ending at vertex 'i'
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v : G[u]) {
            dp[v] = max(dp[v], 1 + dp[u]);
            indegree[v]--;
            if (indegree[v] == 0) {
                Q.push(v);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << nl;
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