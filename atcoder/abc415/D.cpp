/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Get Many Stickers

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
    ll n;
    int m;
    cin >> n >> m;
    vector<array<ll, 3>> A(m);
    for (int i = 0; i < m; i++) {
        ll a, b;
        cin >> a >> b;
        A[i] = {a - b, a, b};
    }
    
    sort(A.begin(), A.end());
    
    ll ans = 0;
    for (int i = 0; i < m; i++) {
        auto [d, a, b] = A[i];
        if (a <= n) {
            ll x = ((n - a) / d) + 1;
            ans += x;
            n -= x * d;
        }
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