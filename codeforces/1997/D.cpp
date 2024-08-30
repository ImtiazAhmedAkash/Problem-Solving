/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Maximize the Root

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    for (int v = 2; v <= n; v++) {
        int u;
        cin >> u;
        G[u].push_back(v);
    }

    int ans = A[1];
    A[1] = 0;

    auto dfs = [&](auto&& self, int u) -> void {
        if (G[u].empty()) return;
        int mini = inf;
        for (auto& v : G[u]) {
            self(self, v);
            mini = min(mini, A[v]);
        }
        if (A[u] >= mini) {
            A[u] = mini;
        } else {
            A[u] = (A[u] + mini) / 2;
        }
    };

    dfs(dfs, 1);

    ans += *min_element(A.begin() + 2, A.end());
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