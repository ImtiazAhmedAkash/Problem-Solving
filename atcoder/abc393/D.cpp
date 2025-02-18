/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Swap to Gather

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
    vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            pos.push_back(i);
        }
    }
    
    if (pos.size() == 1) {
        cout << 0 << nl;
        return;
    }
    
    int mid = pos.size() / 2;
    ll ans = 0;
    for (int i = mid - 1; i >= 0; i--) {
        ans += (pos[i + 1] - 1) - pos[i];
        pos[i] = pos[i + 1] - 1;
    }
    for (int i = mid + 1; i < pos.size(); i++) {
        ans += pos[i] - (pos[i - 1] + 1);
        pos[i] = pos[i - 1] + 1;
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