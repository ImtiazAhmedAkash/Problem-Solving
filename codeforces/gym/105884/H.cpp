/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// H - Litmus Test

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
    string s;
    cin >> s;
    
    map<char, int> mp;
    for (auto &c : s) {
        mp[c]++;
    }
    
    if (mp.count('A') && mp.count('B')) {
        cout << 1 << nl;
    }
    else if (mp['S'] == n) {
        cout << 2 << nl;
    }
    else if (mp.count('S')) {
        cout << n - mp['S'] << nl;
    }
    else {
        cout << n << nl;
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