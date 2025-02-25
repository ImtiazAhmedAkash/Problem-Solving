/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - Insane Problem

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    ll k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    
    ll ans = 0;
    for (ll val = 1; val <= inf; val *= k) {
        // find max r1 such that r1 * k^n <= r2
        ll L = l1 - 1, R = r1;
        while (L < R) {
            ll M = L + (R - L + 1) / 2;
            if (M * val <= r2) {
                L = M;
            }
            else {
                R = M - 1;
            }
        }
        ll r = R;
        if (r < l1) continue;
        
        // find min l1 such that l2 <= l1 * k^n
        L = l1, R = r + 1;
        while (L < R) {
            ll M = L + (R - L) / 2;
            if (l2 <= M * val) {
                R = M;
            }
            else {
                L = M + 1;
            }
        }
        ans += (r - L + 1);
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