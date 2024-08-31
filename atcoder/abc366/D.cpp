/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Cuboid Sum Query

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
    vector A(n + 1, vector(n + 1, vector<ll>(n + 1, 0)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                cin >> A[i][j][k];
            }
        }
    }

    vector pref(n + 1, vector(n + 1, vector<ll>(n + 1, 0)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                ll sum = A[i][j][k];

                sum += pref[i - 1][j][k];
                sum += pref[i][j - 1][k];
                sum += pref[i][j][k - 1];

                sum -= pref[i - 1][j - 1][k];
                sum -= pref[i - 1][j][k - 1];
                sum -= pref[i][j - 1][k - 1];

                sum += pref[i - 1][j - 1][k - 1];

                pref[i][j][k] = sum;
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;

        ll ans = pref[rx][ry][rz];

        ans -= pref[lx - 1][ry][rz];
        ans -= pref[rx][ly - 1][rz];
        ans -= pref[rx][ry][lz - 1];

        ans += pref[lx - 1][ly - 1][rz];
        ans += pref[lx - 1][ry][lz - 1];
        ans += pref[rx][ly - 1][lz - 1];

        ans -= pref[lx - 1][ly - 1][lz - 1];

        cout << ans << nl;
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