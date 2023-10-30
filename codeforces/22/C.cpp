/*  In the Name of ALLAH, the most gracious, the most merciful  */

// System Administrator

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
    int n, m, k;
    cin >> n >> m >> k;

    int min_edge_count = n - 1;
    ll max_edge_count = 1 + 1LL * (n - 1) * (n - 2) / 2;
    if (min_edge_count > m || max_edge_count < m) {
        cout << -1 << nl;
        return;
    }

    int a = k == 1 ? n : k - 1;
    cout << a << " " << k << nl;
    m--;
    for (int i = 1; i <= n && m; i++) {
        if (i == a) continue;
        for (int j = i + 1; j <= n && m; j++) {
            if (j == a || j == i) continue;
            cout << i << " " << j << nl;
            m--;
        }
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