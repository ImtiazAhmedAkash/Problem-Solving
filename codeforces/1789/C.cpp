/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Serval and Toxel's Arrays

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
    vector<int> A(n + 1);
    vector pos(n + m + 1, vector<int>());
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        pos[A[i]].push_back(0);
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        if (A[x] == y) continue;
        pos[A[x]].push_back(i);
        A[x] = y;
        pos[A[x]].push_back(i);
    }
    for (int i = 1; i <= n + m; i++) {
        if (pos[i].size() & 1) {
            pos[i].push_back(m + 1);
        }
    }

    ll ans = 0;
    ll total = 1LL * m * (m + 1) / 2;  // there are total (m + 1) arrays, so (m + 1) * (m + 1 - 1) / 2 pairs.
    for (int i = 1; i <= n + m; i++) {
        if (pos[i].empty()) continue;
        int absent = m + 1;
        for (int j = 1; j < pos[i].size(); j += 2) {
            absent -= pos[i][j] - pos[i][j - 1];
        }
        ans += total - 1LL * absent * (absent - 1) / 2;
    }
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