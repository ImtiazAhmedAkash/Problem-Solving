/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Tetrahedron

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1000000007;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    
    vector<int> dp(4);
    dp[3] = 1;
    for (int moves = 1; moves <= n; moves++) {
        ll prev_total_moves = 0;
        for (int i = 0; i < 4; i++) {
            prev_total_moves = prev_total_moves + dp[i]; 
        }
        for (int i = 0; i < 4; i++) {
            dp[i] = (prev_total_moves - dp[i]) % mod;
        }
    }
    cout << dp[3] << nl;
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