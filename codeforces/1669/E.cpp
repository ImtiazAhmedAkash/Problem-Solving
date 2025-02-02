/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// 2-Letter Strings

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
    vector<string> A(n);
    for (auto &x : A) cin >> x;
    
    ll ans = 0;
    vector cnt(15, vector<int>(15));
    for (int i = n - 1; i >= 0; i--) {
        int curx = A[i].front() - 'a';
        int cury = A[i].back() - 'a';
        
        for (int x = 0; x <= 11; x++) {
            if (x == curx) continue;
            ans += cnt[x][cury];
        }
        
        for (int y = 0; y <= 11; y++) {
            if (y == cury) continue;
            ans += cnt[curx][y];
        }
        cnt[curx][cury]++;
    }
    
    cout << ans << nl;
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