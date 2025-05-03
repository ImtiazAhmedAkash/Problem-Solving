/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Forbidden Difference

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
const int N = 1e6 + 5;

void solve() {
    int n, d;
    cin >> n >> d;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    
    if (d == 0) {
        cout << n - mp.size() << nl;
        return;
    }
    
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        if (mp.find(i) == mp.end()) continue;
        vector<int> A;
        for (int j = i; j <= N; j += d) {
            if (mp.find(j) == mp.end()) break;
            A.push_back(mp[j]);
            mp.erase(j);
        }
        
        int m = A.size();
        vector dp(m + 1, vector<int>(2, -1));
        auto fun = [&](auto&& self, int indx, int ignore) -> int {
            if (indx == m) return 0;
            auto &ret = dp[indx][ignore];
            if (~ret) return ret;
            
            ret = inf;
            ret = min(ret, A[indx] + self(self, indx + 1, 1));
            if (ignore) ret = min(ret, self(self, indx + 1, 0));
            
            return ret;
        };
        
        ans += fun(fun, 0, 1);
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