/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Devyatkino

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
    
    if (s.find('7') != -1) {
        cout << 0 << nl;
        return;
    }
    
    auto found_seven = [&](ll x) -> bool {
        string t = to_string(x);
        if (t.find('7') == -1) return false;
        return true;
    };
    
    int ans = inf;
    int n = s.size();
    ll add = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        ll tmp = stoll(s);
        add = add * 10 + 9;
        while (!found_seven(tmp)) {
            tmp += add;
            cnt++;
        }
        ans = min(ans, cnt);
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