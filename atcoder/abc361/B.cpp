/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Intersection of Cuboids

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
    int a, b, c, d, e, f, g, h, i, j, k, l;
    cin >> a >> b >> c >> d >> e >> f >> g >> h >> i >> j >> k >> l;
    bool x = false, y = false, z = false;
    if ((a <= g && g < d) || (g <= a && a < j)) {
        x = true;
    }
    if ((b <= h && h < e) || (h <= b && b < k)) {
        y = true;
    }
    if ((c <= i && i < f) || (i <= c && c < l)) {
        z = true;
    }
    cout << ((x && y && z) ? "Yes" : "No") << nl;
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