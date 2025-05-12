/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// G - Life is Too Short

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
    string s;
    cin >> s;
    
    int n = s.size();
    vector pos(2, vector<int>());
    for (int i = 0; i < n; i++) {
        pos[s[i] - '0'].push_back(i);
    }
    
    int ans = 0;
    int last = -1;
    while(true) {
        ans++;
        auto zero = upper_bound(pos[0].begin(), pos[0].end(), last);
        auto one = upper_bound(pos[1].begin(), pos[1].end(), last);
        if (zero == pos[0].end() || one == pos[1].end()) break;
        last = max(*one, *zero);
    }
    
    cout << ans << nl;
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