/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1111 - Best Picnic Ever

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
    int k, n, m;
    cin >> k >> n >> m;
    vector<int> S(k);
    for (auto& x : S) cin >> x;
    vector G(n + 1, vector<int>());
    while (m--) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
    }

    vector<int> cnt(n + 1, 0);
    auto bfs = [&](int src) -> void {
        vector<bool> used(n + 1, false);
        queue<int> Q;
        Q.push(src);
        used[src] = true;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            cnt[u]++;
            for (auto v : G[u]) {
                if (!used[v]) {
                    used[v] = true;
                    Q.push(v);
                }
            }
        }
    };

    for (auto x : S) {
        bfs(x);
    }

    int ans = count_if(cnt.begin(), cnt.end(), [&](int x) { return x == k; });
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