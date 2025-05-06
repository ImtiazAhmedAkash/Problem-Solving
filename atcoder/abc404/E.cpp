/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - Bowls and Beans

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
const ll INF = 1e12;
const int mod = 1e9 + 7;
const int N = 1e6;

void solve() {
    int n;
    cin >> n;
    vector<int> C(n);
    for (int i = 1; i < n; i++) {
        cin >> C[i];
    }
    vector<int> A = {0};
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (x) {
            A.push_back(i);
        }
    }
    
    vector<int> dp(n + 1, -1);
    auto fun = [&](auto&& self, int cur, int target) -> int {
        if (cur <= target) return 0;
        auto &ret = dp[cur];
        if (~ret) return ret;
        
        ret = inf;
        for (int i = max(0, cur - C[cur]); i <= cur - 1; i++) {
            ret = min(ret, 1 + self(self, i, target));
        }
        
        return ret;
    };
    
    int ans = 0;
    for (int i = A.size() - 1; i > 0; i--) {
        ans += fun(fun, A[i], A[i - 1]);
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