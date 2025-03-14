/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Sakurako and Water

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

    vector A(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    ll ans = 0;
    for (int x = 0, y = 0; x < n; x++) {
        int cur = inf;
        for (int i = x, j = y; i < n && j < n; i++, j++) {
            cur = min(cur, A[i][j]);
        }
        if (cur < 0) {
            ans += abs(cur);
        }
    }

    for (int x = 0, y = 1; y < n; y++) {
        int cur = inf;
        for (int i = x, j = y; i < n && j < n; i++, j++) {
            cur = min(cur, A[i][j]);
        }
        if (cur < 0) {
            ans += abs(cur);
        }
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