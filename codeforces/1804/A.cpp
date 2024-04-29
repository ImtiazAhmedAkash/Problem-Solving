/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Lame King

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
    int r, c;
    cin >> r >> c;

    r = abs(r);
    c = abs(c);
    int mn = min(r, c);
    int mx = max(r, c);
    int ans = mn + min(mx, mn + 1);
    mx -= min(mx, mn + 1);
    ans += 2 * mx;
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