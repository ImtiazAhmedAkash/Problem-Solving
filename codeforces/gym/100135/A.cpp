/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Ladder

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
    
    vector<int> dp(n + 1, -1);
    auto fun = [&](auto&& self, int indx) -> int {
        if (indx <= 0) return 0;
        if (dp[indx] != -1) return dp[indx];
        return dp[indx] = A[indx] + max(self(self, indx - 1), self(self, indx - 2));
    };
    
    cout << fun(fun, n) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("ladder.in", "r", stdin);
    freopen("ladder.out", "w", stdout);
    
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}