/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Place of the Olympiad

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 2e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 100;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    
    auto check = [&](ll mid) -> bool {
        ll perRow = (m / (mid + 1)) * mid + (m % (mid + 1));
        ll total = perRow * n;
        return total >= k;
    };
    
    ll L = 1, R = inf;
    while (L < R) {
        ll M = L + (R - L) / 2;
        if (check(M)) {
            R = M;
        } 
        else {
            L = M + 1;
        }
    }
    
    cout << L << nl;
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