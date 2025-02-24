/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Remove the Ends

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    vector<ll> pos(n + 1);
    for (int i = 1; i <= n; i++) {
        pos[i] = pos[i - 1];
        if (A[i] > 0) {
            pos[i] += A[i];
        }
    }
    
    vector<ll> neg(n + 2);
    for (int i = n; i > 0; i--) {
        neg[i] += neg[i + 1];
        if (A[i] < 0) {
            neg[i] += abs(A[i]);
        }
    }
    
    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ans = max(ans, pos[i] + neg[i + 1]);
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