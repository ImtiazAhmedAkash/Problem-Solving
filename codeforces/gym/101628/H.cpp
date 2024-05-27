/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Have Some Cheese Bread

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
    int n, c, m;
    cin >> n >> c >> m;

    vector<int> cheese(n + 1);
    for (int i = 0; i < c; i++) {
        int x;
        cin >> x;
        cheese[x] = 1;
    }

    vector G(n + 1, vector<int>());
    vector<int> indegree(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        indegree[v]++;
    }

    vector<int> amount(n + 1, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    amount[1] = cheese[1];
    pq.push({amount[1], 1});
    while (!pq.empty()) {
        auto [x, u] = pq.top();
        pq.pop();

        if (amount[u] != x) continue;

        for (auto v : G[u]) {
            if (amount[u] + cheese[v] < amount[v]) {
                amount[v] = amount[u] + cheese[v];
                pq.push({amount[v], v});
            }
        }
    }

    int mini = amount[n];

    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            Q.push(i);
        }
    }

    fill(amount.begin(), amount.end(), -inf);
    amount[1] = cheese[1];
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (auto v : G[u]) {
            amount[v] = max(amount[v], amount[u] + cheese[v]);
            indegree[v]--;
            if (indegree[v] == 0) {
                Q.push(v);
            }
        }
    }

    int maxi = amount[n];

    cout << mini << " " << maxi << nl;
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