/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Squares in Circle

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e7;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    ll r;
    cin >> r;
    
    auto square = [&](ll x) -> ll {
        return x * x;
    };
    
    ll ans = 0;
    for (ll i = 0; square(2 * i + 1) <= 4 * r * r; i++) {
        ll L = 0, R = inf;
        while (L < R) {
            ll M = L + (R - L + 1) / 2;
            if (square(2 * i + 1) + square(2 * M + 1) <= 4 * r * r) {
                L = M;
            } else {
                R = M - 1;
            }
        }
        ans += R;
    }
    
    cout << 4 * ans + 1 << nl;
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