/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Equilateral Triangle

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
    int n, l;
    cin >> n >> l;
    int cur = 0;
    vector<int> cnt(l + 1);
    cnt[cur]++;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        cur += x;
        cur %= l;
        cnt[cur]++;
    }
    
    if (l % 3) {
        cout << 0 << nl;
        return;
    }
    
    int d = l / 3;
    ll ans = 0;
    for (int i = 0; i < l; i++) {
        int b = i;
        int a = b - d;
        int c = b + d;
        if (a >= 0 && c < l) {
            ans += 1LL * cnt[a] * cnt[b] * cnt[c];
        }
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