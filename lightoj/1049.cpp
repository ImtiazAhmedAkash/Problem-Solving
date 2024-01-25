/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1049 - One Way Roads

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
    vector G(n + 1, vector<int>());
    map<pair<int, int>, int> M;
    for (int i = 0; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(v);
        G[v].push_back(u);
        M[{v, u}] = w;
    }

    int ans = inf, cur_cost = 0;
    int cur_pos = 1, nxt_pos = G[1].front();
    for (int i = 0; i < n; i++) {
        if (M.find({cur_pos, nxt_pos}) != M.end()) {
            cur_cost += M[{cur_pos, nxt_pos}];
        }
        if (G[nxt_pos].front() == cur_pos) {
            cur_pos = nxt_pos;
            nxt_pos = G[nxt_pos].back();
        } else {
            cur_pos = nxt_pos;
            nxt_pos = G[nxt_pos].front();
        }
    }
    ans = min(ans, cur_cost);

    cur_cost = 0;
    cur_pos = 1, nxt_pos = G[1].back();
    for (int i = 0; i < n; i++) {
        if (M.find({cur_pos, nxt_pos}) != M.end()) {
            cur_cost += M[{cur_pos, nxt_pos}];
        }
        if (G[nxt_pos].front() == cur_pos) {
            cur_pos = nxt_pos;
            nxt_pos = G[nxt_pos].back();
        } else {
            cur_pos = nxt_pos;
            nxt_pos = G[nxt_pos].front();
        }
    }
    ans = min(ans, cur_cost);

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}