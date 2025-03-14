/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Word Cut

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
const int mod = 1000000007;
const int N = 2e5 + 5;

void solve() {
    string s, t;
    cin >> s >> t;
    int op;
    cin >> op;
    
    int n = s.size();
    vector<bool> good(n, true);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[(i + j) % n] != t[j]) good[i] = false;
        }
    }
    
    vector<ll> dp(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = (good[i] ? 1 : 0);
        sum += dp[i];
    }
    
    while (op--) {
        vector<ll> newDp(n);
        ll newSum = 0;
        for (int i = 0; i < n; i++) {
            newDp[i] = (sum - dp[i] + mod) % mod;
            newSum += newDp[i];
            newSum %= mod;
        }
        sum = newSum;
        dp = newDp;
    }
    
    cout << dp[0] << nl;
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