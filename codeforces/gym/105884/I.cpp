/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// I - XOR This OR That

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
const ll INF = 1e12;
const int mod = 1e9 + 7;
const int N = 1e6;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    if (n > 20) {
        cout << 0 << nl;
        return;
    }
    
    ll ans = INF;
    for (int mask = 1; mask < (1 << n) - 1; mask++) {
        int Xor = 0;
        int Or = 0;
        for (int bit = 0; bit < n; bit++) {
            if (mask & (1 << bit)) {
                Xor ^= A[bit];
            }
            else {
                Or |= A[bit];
            }
        }
        
        ans = min(ans, 1LL * Xor * Or);
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