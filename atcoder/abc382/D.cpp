/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Keep Distance

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

    vector<vector<int>> ans;

    auto dfs = [&](auto &&self, vector<int> A) -> void {
        if (A.size() == n) {
            ans.push_back(A);
            return;
        }

        int cur = 1;
        int x = A.size();
        if (!A.empty()) {
            cur = A.back() + 10;
        }
        for (int i = cur; i + (n - x - 1) * 10 <= m; i++) {
            A.push_back(i);
            self(self, A);
            A.pop_back();
        }
    };

    dfs(dfs, vector<int>());

    cout << ans.size() << nl;
    for (auto &v : ans) {
        for (auto &x : v) {
            cout << x << " ";
        }
        cout << nl;
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