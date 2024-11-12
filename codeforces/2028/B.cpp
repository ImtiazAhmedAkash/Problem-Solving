/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Alice's Adventures in Permuting

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
    ll n, b, c;
    cin >> n >> b >> c;

    ll ans = -1;
    if (n <= c) {
        ans = n;
    } else if (b == 0 && n - c <= 2) {
        ans = n - 1;
    } else if (b != 0) {
        ll cur = 1 + (n - 1 - c) / b;
        ans = n - cur;
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