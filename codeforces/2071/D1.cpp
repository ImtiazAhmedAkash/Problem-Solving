/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D1 - Infinite Sequence (Easy Version)

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
    ll n, l, r;
    cin >> n >> l >> r;
    vector<int> A(n + 1), pref(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        pref[i] = pref[i - 1] ^ A[i];
    }
    
    if (n % 2 == 0) {
        n++;
        A.push_back(pref[n / 2]);
        pref.push_back(pref.back() ^ A.back());
    }
    
    if (l <= n) {
        cout << A[l] << nl;
        return;
    }
    
    auto fun = [&](auto&& self, ll cur) -> int {
        if (cur <= n) return pref[cur];
        if (cur & 1) return pref[n];
        return (pref[n] ^ self(self, cur / 2));
    };
    
    cout << fun(fun, l / 2) << nl;
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