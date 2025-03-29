/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// A - Hungry Student Problem

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
const int N = 100;

vector<int> dp(N + 5);
void precalculate() {
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i] = (i >= 3 && dp[i - 3]) | (i >= 7 && dp[i - 7]);
    }
}

void solve() {
    int n;
    cin >> n;
    cout << (dp[n] ? "YES" : "NO") << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    precalculate();
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}