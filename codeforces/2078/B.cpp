/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Vicious Labyrinth

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
    int n, k;
    cin >> n >> k;
    
    vector<int> ans(n + 1);
    if (k & 1) {
        for (int i = 1; i <= n; i++) {
            ans[i] = n;
        }
        ans[n] = n - 1;
    }
    else {
        for (int i = 1; i <= n; i++) {
            ans[i] = n - 1;
        }
        ans[n - 1] = n;
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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