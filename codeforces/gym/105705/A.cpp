/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Max Xor Pair

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
    int n, x;
    cin >> n >> x;
    
    int ans = 0;
    if (n == 3) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == x || j == x) continue;
                ans = max(ans, (i ^ j));
            }
        }
        
        cout << ans << nl;
        return;
    }
    
    if ((n & (n - 1)) == 0) {
        if (n == x) ans = n - 1;
        else if (n - 1 == x) ans = n ^ (n - 2);
        else ans = n ^ (n - 1);
    }
    else {
        int closestPowerOfTwo = 1 << (__lg(n));
        ans = closestPowerOfTwo ^ (closestPowerOfTwo - 1);
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