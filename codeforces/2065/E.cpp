/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Skibidus and Rizz

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
    int n, m, k;
    cin >> n >> m >> k;

    string ans;
    if (n > m) {
        for (int i = 0; i < min(n, k); i++) ans += '0';
        n -= min(n, k);
    }
    else {
        for (int i = 0; i < min(m, k); i++) ans += '1';
        m -= min(m, k);
    }
    while (n && m) {
        if (!ans.empty() && ans.back() == '0') {
            ans += '1';
            m--;
        }
        else {
            ans += '0';
            n--;
        }
    }
    while (n--) {
        ans += '0';
    }
    while (m--) {
        ans += '1';
    }
    
    auto calculate = [&](char c) -> int {
        int cnt = 0;
        int mx = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == c) cnt++;
            else cnt--;
            mx = max(mx, cnt);
            cnt = max(0, cnt);
        }
        return mx;
    };
    
    int mx = max(calculate('0'), calculate('1'));
    
    if (mx == k) {
        cout << ans << nl;
    }
    else {
        cout << -1 << nl;
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