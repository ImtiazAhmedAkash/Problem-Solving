/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Dual Trigger

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
    
    vector<int> one;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            one.push_back(i);
        }
    }
    
    if (one.size() & 1) {
        cout << "NO" << nl;
        return;
    }
    
    if (one.size() == 2 && one.front() + 1 == one.back()) {
        cout << "NO" << nl;
    }
    else {
        cout << "YES" << nl;
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