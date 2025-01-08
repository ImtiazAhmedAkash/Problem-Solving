/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Bewitching Stargazer

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
    int n, k;
    cin >> n >> k;
    
    auto dfs = [&](auto&& self, int n) -> pair<ll, ll> {
        if (n < k) return {0, 0};
        int mid = (n + 1) / 2;
        if (n & 1) {
            auto [sum, cnt] = self(self, mid - 1);
            ll ans = sum + sum + (cnt * mid) + mid;
            return {ans, 2 * cnt + 1};
        } else {
            auto [sum, cnt] = self(self, mid);
            ll ans = sum + sum + (cnt * mid);
            return {ans, 2 * cnt};
        }
    };
    
    cout << dfs(dfs, n).first << nl;
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