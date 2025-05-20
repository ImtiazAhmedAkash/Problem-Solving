/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - Unpleasant Strings

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
    string s;
    cin >> s;
    
    vector nxt(n + 5, vector<int>(k, n));
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--) {
        int pos = *max_element(nxt[i + 1].begin(), nxt[i + 1].end());
        dp[i] = 1 + dp[pos];
        nxt[i] = nxt[i + 1];
        nxt[i][s[i] - 'a'] = i;
    }
    
    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int indx = -1;
        for (auto &c : t) {
            indx = nxt[indx + 1][c - 'a'];
        }
        
        cout << dp[indx] << nl;
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