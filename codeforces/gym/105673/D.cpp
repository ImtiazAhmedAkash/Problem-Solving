/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Fat Burner

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    vector dp(n + 1, vector(2, vector<ll>(2, -1)));
    // secondLast = 1 -> worked on the day before yesterday
    // last = 1 -> worked on yesterday
    auto fun = [&](auto&& self, int indx, int secondLast, int last) -> ll {
        if (indx == n + 1) return 0;
        auto& ans = dp[indx][secondLast][last];
        if (~ans) return ans;
        
        ans = 0;
        ans = max(ans, self(self, indx + 1, last, 0));
        
        if (secondLast == 1) {
            if (last == 1) {
                ans = max(ans, A[indx] + self(self, indx + 1, last, 1));
            } else {
                ans = max(ans, 3 * A[indx] + self(self, indx + 1, last, 1));    
            }
        }
        else {
            if (last == 1) {
                ans = max(ans, 2 * A[indx] + self(self, indx + 1, last, 1));
            } else {
                ans = max(ans, 4 * A[indx] + self(self, indx + 1, last, 1));
            }
        }
        
        return ans;
    };
    
    cout << fun(fun, 1, 0, 0) << nl;
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