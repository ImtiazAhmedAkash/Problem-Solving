/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Ice Cream Balls

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    ll n;
    cin >> n;
    ll L = 0, R = 2648956430;
    while (L < R) {
        ll M = L + (R - L) / 2;
        __int128_t total = M * (M - 1) / 2;
        if (total == n) {
            cout << M << nl;
            return;
        }
        if (total > n) R = M;
        else L = M + 1;
    }
    ll x = (L - 1) * (L - 2) / 2;
    ll ans = L - 1 + (n - x);
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