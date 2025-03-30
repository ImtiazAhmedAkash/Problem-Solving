/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Polo the Penguin and Matrix

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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> A(n * m);
    for (auto &x : A) cin >> x;
    
    sort(A.begin(), A.end());
    
    int target = A[(n * m) / 2];
    int ans = 0;
    for (int i = 0; i < n * m; i++) {
        int diff = abs(target - A[i]);
        if (diff % d) {
            cout << -1 << nl;
            return;
        }
        ans += diff / d;
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