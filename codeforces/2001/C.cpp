/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Guess The Tree

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

int query(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> ans;

    vector<bool> used(n + 1, false);
    auto dfs = [&](auto&& self, int u, int v) -> void {
        if (used[u]) return;
        int x = query(u, v);
        if (x == u) {
            ans.push_back({u, v});
            used[u] = true;
            return;
        }
        self(self, u, x);
        self(self, x, v);
    };

    for (int i = 2; i <= n; i++) {
        dfs(dfs, i, 1);
    }

    cout << "! ";
    for (auto& [a, b] : ans) {
        cout << a << " " << b << " ";
    }
    cout << endl;
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