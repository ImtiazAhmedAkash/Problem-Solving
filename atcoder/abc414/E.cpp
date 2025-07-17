/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - Count A%B=C

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

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b /= 2;
    }
    return ans;
}
int inverseMod(int a) {
    return power(a, mod - 2);
}

void solve() {
    ll n;
    cin >> n;
    
    ll ans = (n % mod) * ((n + 1) % mod) % mod;
    ans = (ans * inverseMod(2)) % mod;
    
    ll bad = 0;
    for (ll l = 1; l <= n; ) {
        ll q = n / l;
        ll r = n / q + 1;
        bad += ((r - l) % mod) * (q % mod);
        bad %= mod;
        l = r;
    }
    
    ans = (ans - bad + mod) % mod;
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