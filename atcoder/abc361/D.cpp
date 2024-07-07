/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Go Stone Puzzle

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
    string s, t;
    cin >> s >> t;
    s += "..";
    t += "..";

    queue<pair<string, int>> Q;  // Q = {string, position of the first empty cell}
    map<string, int> dist;
    Q.push({s, n});
    dist[s] = 0;

    while (!Q.empty()) {
        auto [u, dot] = Q.front();
        Q.pop();

        if (u == t) {
            cout << dist[t] << nl;
            return;
        }

        // the empty cells will always be consecutive i.e. dot and dot + 1 contains the empty cells.
        for (int i = 0; i <= n; i++) {
            if (i == dot || i == dot + 1 || i + 1 == dot) continue;
            string cur = u;
            cur[dot] = u[i];
            cur[dot + 1] = u[i + 1];
            cur[i] = cur[i + 1] = '.';
            if (dist.count(cur) == 0) {
                dist[cur] = dist[u] + 1;
                Q.push({cur, i});
            }
        }
    }

    cout << -1 << nl;
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