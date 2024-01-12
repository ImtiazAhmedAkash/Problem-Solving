/*  In the Name of ALLAH, the most gracious, the most merciful  */

// CHEFPRODUCT - Chef Product

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
    ll n;
    cin >> n;
    if (n == 2) {
        cout << 0 << nl;
        return;
    }
    ll R = sqrtl(n) + 2;
    while (R * R > n) {
        R--;
    }
    ll ans = (n & 1 ? (R + 1) / 2 : R / 2);
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