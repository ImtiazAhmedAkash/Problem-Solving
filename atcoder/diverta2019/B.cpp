/*  In the Name of ALLAH, the most gracious, the most merciful  */

// RGB Boxes

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 3000;

void solve() {
    int r, g, b, n;
    cin >> r >> g >> b >> n;
    int ans = 0;
    for (int i = 0; i <= n / r; i++) {
        for (int j = 0; j <= n / g; j++) {
            int cur = r * i + g * j;
            if (cur > n) break;
            int rem = n - cur;
            if (rem % b == 0) ans++;
        }
    }
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