/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Between a and b ...

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 1e7 + 5;

void solve() {
    ll a, b, x;
    cin >> a >> b >> x;
    ll ans = b / x;
    if (a == 0) ans++;
    else ans -= (a - 1) / x;
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