/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Nearest Opposite Parity

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
    vector<int> A(n + 1);
    vector<int> even, odd;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        if (A[i] & 1) {
            odd.push_back(i);
        } else {
            even.push_back(i);
        }
    }

    vector G(n + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        if (i + A[i] <= n) {
            G[i + A[i]].push_back(i);
        }
        if (i - A[i] > 0) {
            G[i - A[i]].push_back(i);
        }
    }

    vector<int> ans(n + 1, -1);
    auto bfs = [&](vector<int> &from, vector<int> &to) -> void {
        vector<int> dist(n + 1, inf);
        queue<int> q;
        for (auto &v : from) {
            q.push(v);
            dist[v] = 0;
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &v : G[u]) {
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        for (auto &v : to) {
            if (dist[v] != inf) {
                ans[v] = dist[v];
            }
        }
    };

    bfs(even, odd);
    bfs(odd, even);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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