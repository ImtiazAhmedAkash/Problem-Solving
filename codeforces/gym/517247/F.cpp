/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Tree Again!

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
    vector<char> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector G(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int m;
    cin >> m;
    string s;
    cin >> s;
    vector<int> tmp(26);
    for (auto c : s) {
        tmp[c - 'a']++;
    }

    vector cnt(n + 1, vector<int>(26));
    auto dfs = [&](auto&& self, int u, int par = 0) -> void {
        cnt[u][A[u] - 'a']++;
        for (auto v : G[u]) {
            if (v == par) continue;
            self(self, v, u);
            for (int i = 0; i < 26; i++) {
                cnt[u][i] += cnt[v][i];
            }
        }
    };

    dfs(dfs, 1);
    for (int i = 1; i <= n; i++) {
        bool ok = true;
        for (int j = 0; j < 26; j++) {
            if (cnt[i][j] < tmp[j]) {
                ok = false;
                break;
            }
        }
        cout << (ok ? 1 : 0) << " \n"[i == n];
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