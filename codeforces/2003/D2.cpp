/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Turtle and a MEX Problem (Hard Version)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

ll range_sum(ll l, ll r) {
    if (l > r) return 0;
    ll x = r * (r + 1) / 2;
    ll y = l * (l - 1) / 2;
    return x - y;
}

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> G;
    int mx = 0;
    int first_mex = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        set<int> st;
        while (k--) {
            int x;
            cin >> x;
            st.insert(x);
        }

        int mex = 0;
        while (st.find(mex) != st.end()) mex++;
        int u = mex++;
        first_mex = max(u, first_mex);
        while (st.find(mex) != st.end()) mex++;
        int v = mex;
        mx = max(mx, v);
        G[u].push_back(v);
    }

    vector<int> dp(mx + 5, -1);
    auto dfs = [&](auto&& self, int u) -> void {
        dp[u] = u;
        if (G.find(u) == G.end()) {
            return;
        }
        for (auto& v : G[u]) {
            if (dp[v] == -1) {
                self(self, v);
            }
            dp[u] = max(dp[u], dp[v]);
        }
    };

    for (int i = 0; i <= mx; i++) {
        if (dp[i] == -1) {
            dfs(dfs, i);
        }
        if (G.count(i) && G[i].size() > 1) {
            first_mex = max(first_mex, dp[i]);
        }
    }

    int bound = min(mx, m);
    ll ans = 0;
    for (int i = 0; i <= bound; i++) {
        ans += max(first_mex, dp[i]);
    }
    ans += range_sum(bound + 1, m);

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}