/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Black Intervals

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
    int n, q;
    cin >> n >> q;
    
    vector<char> col(n + 5, 'w');
    int ans = 0;
    while (q--) {
        int x;
        cin >> x;
        
        if (col[x] == 'w') {
            if (col[x - 1] == 'w' && col[x + 1] == 'w') ans++;
            else if (col[x - 1] == 'b' && col[x + 1] == 'b') ans--;
            col[x] = 'b';
        }
        else {
            if (col[x - 1] == 'w' && col[x + 1] == 'w') ans--;
            else if (col[x - 1] == 'b' && col[x + 1] == 'b') ans++;
            col[x] = 'w';
        }
        
        cout << ans << nl;
    }
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