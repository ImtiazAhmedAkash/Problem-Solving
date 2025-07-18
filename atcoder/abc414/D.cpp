/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Transmission Mission

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
    vector<ll> A(n);
    for (auto &x : A) cin >> x;
    
    sort(A.begin(), A.end());
    
    vector<ll> B;
    for (int i = 1; i < n; i++) {
        B.push_back(A[i] - A[i - 1]);
    }
    
    sort(B.begin(), B.end());
    
    ll ans = 0;
    for (int i = 0; i < n - k; i++) {
        ans += B[i];
    }
    
    cout << ans << nl;
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