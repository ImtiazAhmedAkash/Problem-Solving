/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Cannonballs

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 780;
const int nax = 3e5;

vector<int> pref(N);
vector<int> dp(nax + 5, -1);

void precalculate() {
    for (int i = 1; i <= N; i++) {
        pref[i] = i * (i + 1) / 2;
        pref[i] += pref[i - 1];
    }
}

void solve() {
    int n;
    cin >> n;
    
    auto fun = [&](auto&& self, int n) -> int {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];
        int ans = inf;
        for (int i = 1; i <= N && pref[i] <= n; i++) {
            ans = min(ans, 1 + self(self, n - pref[i]));
        }
        return dp[n] = ans;
    };
    
    cout << fun(fun, n) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    precalculate();
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}