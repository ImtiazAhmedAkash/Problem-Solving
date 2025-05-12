/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// F - Bitwise Battle

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
    int n;
    cin >> n;
    int mxEven = 0, mxOdd = 0;
    int even = 0, odd = 0;
    
    while (n--) {
        int x;
        cin >> x;
        if (x & 1) {
            odd++;
            mxOdd = max(x, mxOdd);
        }
        else {
            even++;
            mxEven = max(x, mxEven);
        }
    }
    
    if (odd == 0 || even == 0) {
        cout << -1 << nl;
        return;
    }
    
    cout << ((odd & 1) ? mxEven : mxOdd) << nl;
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