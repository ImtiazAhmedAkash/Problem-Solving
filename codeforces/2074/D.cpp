/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Counting Points

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    vector<int> R(n);
    for (auto &x : R) cin >> x;
    
    auto find_y = [&](ll x, ll r) -> ll {
        // equation of circle => x^2 + y^2 = r^2
        ll val = r * r - x * x;
        ll sq = sqrtl(val) + 5;
        while (sq * sq > val) sq--;
        return 2 * sq + 1;
    };
    
    map<ll, ll> mp;
    for (int i = 0; i < n; i++) {
        for (int x = A[i] - R[i]; x <= A[i] + R[i]; x++) {
            mp[x] = max(mp[x], find_y(A[i] - x, R[i]));
        }
    }
    
    ll ans = 0;
    for (auto &[x, y] : mp) {
        ans += y;
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