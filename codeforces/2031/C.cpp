/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Penchick and BBQ Buns

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

bool isSquare(int x) {
    int sq = sqrt(x) + 5;
    while (sq * sq > x) sq--;
    return sq * sq == x;
}

void solve() {
    int n;
    cin >> n;
    
    if ((n & 1) && n < 27) {
        cout << -1 << nl;
        return;
    }
    
    vector<int> ans(n + 1);
    if (n % 2 == 0) {
        for (int i = 1, val = 1; i <= n; i += 2, val++) {
            ans[i] = val;
            ans[i + 1] = val;
        }
    }
    else {
        int val = 1;
        ans[1] = ans[10] = ans[26] = val++;
        for (int i = 2; i < 10; i += 2, val++) {
            ans[i] = val;
            ans[i + 1] = val;
        }
        ans[11] = ans[27] = val++;
        for (int i = 12; i < 26; i += 2, val++) {
            ans[i] = val;
            ans[i + 1] = val;
        }
        for (int i = 28; i < n; i += 2, val++) {
            ans[i] = val;
            ans[i + 1] = val;
        }
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