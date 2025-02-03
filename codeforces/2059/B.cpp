/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Cost of the Array

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
    int n, k;
    cin >> n >> k;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    if (n == k) {
        int ans = 1;
        for (int i = 2; i <= n; i += 2) {
            if (A[i] != ans) break;
            ans++;
        }
        cout << ans << nl;
    }
    else {
        for (int i = 2; i <= n - k + 2; i++) {
            if (A[i] != 1) {
                cout << 1 << nl;
                return;
            }
        }
        cout << 2 << nl;
    }
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