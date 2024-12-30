/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Three Strings

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
    string a, b, c;
    cin >> a >> b >> c;
    
    int sa = a.size();
    int sb = b.size();
    int sc = c.size();
    
    vector dp(sa + 1, vector<int>(sb + 1, -1));
    auto fun = [&](auto&& self, int i, int j) -> int {
        if (i == sa && j == sb) return 0;
        auto &ans = dp[i][j];
        if (~ans) return ans;
        
        ans = 0;
        if (i < sa) {
            ans = max(ans, self(self, i + 1, j));
            if (a[i] == c[i + j]) {
                ans = max(ans, 1 + self(self, i + 1, j));
            } 
        }
        if (j < sb) {
            ans = max(ans, self(self, i, j + 1));
            if (b[j] == c[i + j]) {
                ans = max(ans, 1 + self(self, i, j + 1));
            }
        }
        
        return ans;
    };
    
    int good = fun(fun, 0, 0);
    cout << sc - good << nl;
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