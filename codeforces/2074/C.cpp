/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - XOR and Triangle

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
    int x;
    cin >> x;
    
    int msb = __lg(x);
    if ((x & (x + 1)) == 0 || ((x & (x - 1)) == 0)) {
        cout << -1 << nl;
        return;
    }
    
    int ans = 0;
    bool need = true;
    for (int bit = 0; bit < msb; bit++) {
        if (x & (1 << bit)) {
            ans |= (1 << bit);
        }
        else if (need) {
            ans |= (1 << bit);
            need = false;
        }
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