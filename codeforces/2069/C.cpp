/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Beautiful Sequence

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
    
    int indx = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == 1) {
            indx = i;
            break;
        }
    }
    
    ll total = 0, cur = 0, carry = 0;
    ll ans = 0;
    for (int i = indx; i < n; i++) {
        if (A[i] == 1) carry++;
        else if (A[i] == 2) {
            cur *= 2;
            cur += carry;
            cur %= mod;
            total += cur;
            total %= mod;
            carry = 0;
        }
        else {
            ans += total;
            ans %= mod;
        }
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