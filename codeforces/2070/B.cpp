/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Robot Program

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
    ll n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    
    int cur = 0;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') cur++;
        else cur--;
        if (!mp.count(cur)) {
            mp[cur] = i + 1;
        }
    }
    
    ll ans = 0;
    if (mp.count(-x)) {
        ans++;
        k -= mp[-x];
        if (mp.count(0)) {
            ans += k / mp[0];
        }
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