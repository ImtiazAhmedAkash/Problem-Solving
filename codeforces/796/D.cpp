/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Police Stations

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
    int n, k, d;
    cin >> n >> k >> d;
    set<int> st;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        st.insert(x);
    }

    vector G(n + 1, vector<pair<int, int>>());
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
    }

    set<int> ans;
    vector<int> dist(n + 1, inf);

    queue<pair<int, int>> q;
    for (auto &x : st) {
        q.push({x, 0});
        dist[x] = 0;
    }

    while (!q.empty()) {
        auto [u, par] = q.front();
        q.pop();

        for (auto &[v, r] : G[u]) {
            if (v == par) continue;
            if (dist[v] != inf) {
                ans.insert(r);
            } else if (dist[u] + 1 < dist[v] && dist[u] + 1 <= d) {
                dist[v] = dist[u] + 1;
                q.push({v, u});
            }
        }
    }

    cout << ans.size() << nl;
    for (auto &x : ans) {
        cout << x << " ";
    }
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