/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Skibidus and Fanum Tax (hard version)

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
    int n, m;
    cin >> n >> m;
    vector<ll> A(n);
    for (auto &x : A) cin >> x;
    vector<ll> B(m);
    for (auto &x : B) cin >> x;
    
    sort(B.begin(), B.end());
    
    ll x = A[0];
    for (int i = 0; i < m; i++) {
        x = min(x, B[i] - A[0]);
    }
    A[0] = x;
    
    for (int i = 1; i < n; i++) {
        ll target = A[i - 1] + A[i];
        int indx = lower_bound(B.begin(), B.end(), target) - B.begin();
        if (indx < m) {
            x = A[i];
            ll y = B[indx] - A[i];
            if (A[i - 1] <= x && A[i - 1] <= y) {
                A[i] = min(x, y);
            }
            else if (A[i - 1] <= y) {
                A[i] = y;
            }
        }
    }
    
    cout << (is_sorted(A.begin(), A.end()) ? "YES" : "NO") << nl;
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