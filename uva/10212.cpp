/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 10212 - The Last Non-zero Digit.

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9;
const int N = 2e5;

ll erase_trailing_zeroes(ll x) {
    while (x > 0 and x % 10 == 0) {
        x /= 10;
    }
    return x % mod;
}

void solve() {
    int n, m;
    while (cin >> n >> m) {
        ll ans = 1;
        for (int i = n; i > n - m; i--) {
            ans = erase_trailing_zeroes(ans * i);
        }
        cout << ans % 10 << nl;
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