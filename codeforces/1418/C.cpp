/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Mortal Kombat Tower

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
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& x : A) cin >> x;
    
    vector dp(n, vector<int>(2, -1));
    auto fun = [&](auto&& self, int indx, int p) -> int {
        if (indx >= n) return 0;
        
        auto& ans = dp[indx][p];
        if (ans != -1) return ans;
        
        ans = inf;
        if (p == 0) {
            ans = min(ans, A[indx] + self(self, indx + 1, p ^ 1));
            if (indx + 1 < n) {
                ans = min(ans, A[indx] + A[indx + 1] + self(self, indx + 2, p ^ 1));
            }
        } else {
            ans = min({ans, self(self, indx + 1, p ^ 1), self(self, indx + 2, p ^ 1)});
        }
        
        return ans;
    };
    
    cout << fun(fun, 0, 0) << nl;
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