/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Road Optimization

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, l, k;
    cin >> n >> l >> k;
    vector<int> A(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    A.back() = l;
    
    vector<int> S(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> S[i];
    }
    
    vector dp(n + 5, vector<int>(k + 5, -1));
    auto fun = [&](auto&& self, int indx, int rem) -> int {
        if (indx == n + 1) return 0;
        auto& ans = dp[indx][rem];
        if (~ans) return ans;
        
        ans = inf;
        ans = min(ans, (A[indx + 1] - A[indx]) * S[indx] + self(self, indx + 1, rem));
        for (int i = 1; i <= rem; i++) {
            int next = indx + i + 1;
            if (next > n + 1) break;
            ans = min(ans, (A[next] - A[indx]) * S[indx] + self(self, next, rem - i));
        }
        
        return ans;
    };
    
    cout << fun(fun, 1, k) << nl;
    
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