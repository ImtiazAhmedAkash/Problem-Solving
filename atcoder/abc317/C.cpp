/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Remembering the Days

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n, -1));
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        a[u][v] = a[v][u] = w;
    }
    vector<int> b(n);
    iota(b.begin(), b.end(), 0); // b = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int ans = 0;
    do {
        int tmp = 0;
        for (int i = 1; i < n; i++) {
            if (a[b[i]][b[i - 1]] == -1) break;
            tmp += a[b[i]][b[i - 1]];
        }
        ans = max(ans, tmp);
    } while (next_permutation(b.begin(), b.end()));
    cout << ans << nl;
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