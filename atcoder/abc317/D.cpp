/*  In the Name of ALLAH, the most gracious, the most merciful  */

// President

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 1e5 + 5;

vector<ll> vote, seat;
vector<vector<ll>> dp(105, vector<ll>(N, -1));

ll solve (int n, ll need) {
    if (need <= 0) return 0;
    if (n == 0 && need > 0) return INF;
    
    if (dp[n][need] != -1) return dp[n][need];
    
    return dp[n][need] = min(vote[n - 1] + solve(n - 1, need - seat[n - 1]), solve(n - 1, need));
}

void solve() {
    int n;
    cin >> n;
    ll cur = 0, total = 0;
    for (int i = 0; i < n; i++) {
        ll x, y, z;
        cin >> x >> y >> z;
        total += z;
        if (x > y) cur += z;
        else {
            vote.push_back((x + y + 1) / 2 - x);
            seat.push_back(z);
        }
    }
    ll need = (total + 1) / 2 - cur;
    cout << solve(vote.size(), need) << nl;
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