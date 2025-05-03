/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - K-bonacci

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
const int mod = 1e9;
const int N = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    
    if (n < k) {
        cout << 1 << nl;
        return;
    }
    
    vector<ll> A(n + 1, 1);
    A[k] = k;
    ll sum = k + k;
    for (int i = k + 1; i <= n; i++) {
        sum = (sum - A[i - k - 1] + mod) % mod;
        A[i] = sum;
        sum += A[i];
        sum %= mod;
    }
    
    cout << A[n] << nl;
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