/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Creating Keys for StORages Has Become My Main Skill

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
    int n, x;
    cin >> n >> x;
    
    vector<int> ans;
    int cur_or = 0;
    int cur = 0;
    while (ans.size() < n - 1 && (x & cur) == cur) {
        ans.push_back(cur);
        cur_or |= cur;
        cur++;
    }
    if (ans.size() == n - 1 && (cur_or | cur) == x) {
        ans.push_back(cur);
    }
    
    while (ans.size() < n) {
        ans.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << nl;
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