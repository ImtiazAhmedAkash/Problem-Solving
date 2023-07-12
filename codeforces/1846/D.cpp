/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Rudolph and Christmas Tree

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, base, height;
    cin >> n >> base >> height;
    vector<int> pos(n);
    for (auto &x : pos) cin >> x;
    ld ans = 0.0;
    for (int i = 0; i < n; i++) {
        if (i == n - 1 || pos[i + 1] - pos[i] >= height) {
            ans += 0.5 * base * height;
        } else {
            int trap_height = pos[i + 1] - pos[i];
            ld extra_len = 2.0 * trap_height * (base / 2.0) / height;
            ld base_2 = base - extra_len;
            ans += 0.5 * (base + base_2) * trap_height;
        }
    }

    cout << fixed << setprecision(12);
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}