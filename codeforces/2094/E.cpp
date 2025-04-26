/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - Boneca Ambalabu

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    vector<int> cnt(35, 0);
    for (int i = 0; i < n; i++) {
        for (int bit = 0; bit < 30; bit++) {
            if (A[i] & (1 << bit)) {
                cnt[bit]++;
            }
        }
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll cur = 0;
        for (int bit = 0; bit < 30; bit++) {
            if (A[i] & (1 << bit)) {
                cur += 1LL * (n - cnt[bit]) * (1 << bit);
            }
            else {
                cur += 1LL * cnt[bit] * (1 << bit);
            }
        }
        ans = max(ans, cur);
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