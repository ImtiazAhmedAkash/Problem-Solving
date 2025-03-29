/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Given Length and Sum of Digits...

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
    int n, sum;
    cin >> n >> sum;
    
    if (9 * n < sum) {
        cout << "-1 -1" << nl;
        return;
    }
    
    if (sum == 0) {
        cout << (n == 1 ? "0 0" : "-1 -1") << nl;
        return;
    }
    
    int tmp = sum;
    string mini;
    for (int i = 1; i <= n; i++) {
        int j = (i == 1 ? 1 : 0);
        for (j; j <= 9; j++) {
            if (tmp - j <= 9 * (n - i)) {
                mini += '0' + j;
                tmp -= j;
                break;
            }
        }
    }
    
    tmp = sum;
    string maxi;
    for (int i = 1; i <= n; i++) {
        int x = min(9, tmp);
        tmp -= x;
        maxi += '0' + x;
    }
    
    cout << mini << " " << maxi << nl;
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