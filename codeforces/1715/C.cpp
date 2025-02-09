/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Monoblock

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
    int n, q;
    cin >> n >> q;
    vector<int> A(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] != A[i - 1]) {
            ans += 1LL * i * (n - i + 1);
        }
        else {
            ans += (n - i + 1);
        }
    }
    
    while (q--) {
        int i, val;
        cin >> i >> val;
        
        if (A[i - 1] == A[i]) {
            // total contribution for 'i' = 1LL * i * (n - i + 1)
            // counted = 1LL * (n - i + 1)
            // increase = 1LL * (i - 1) * (n - i + 1)
            ans += 1LL * (i - 1) * (n - i + 1);
        }
        if (A[i] == A[i + 1]) {
            // total contribution for 'i + 1' = 1LL * (i + 1) * (n - (i + 1) + 1)
            // counted = 1LL * (n - (i + 1) + 1)
            // increase = 1LL * i * (n - (i + 1) - 1)
            ans += 1LL * i * (n - (i + 1) + 1);
        }
        
        A[i] = val;
        if (A[i - 1] == A[i]) {
            ans -= 1LL * (i - 1) * (n - i + 1);
        }
        if (A[i] == A[i + 1]) {
            ans -= 1LL * i * (n - (i + 1) + 1);
        }
        
        cout << ans << nl;
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