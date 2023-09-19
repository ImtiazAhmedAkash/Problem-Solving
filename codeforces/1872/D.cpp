/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Plus Minus Permutation

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    ll LCM = lcm(x, y);
    ll dx = (n / x) - (n / LCM);
    ll dy = (n / y) - (n / LCM);
    ll ans = (n * (n + 1) / 2) - ((n - dx) * (n - dx + 1) / 2);
    ans -= dy * (dy + 1) / 2;
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