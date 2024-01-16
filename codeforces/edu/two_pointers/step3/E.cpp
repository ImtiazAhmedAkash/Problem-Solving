/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Knapsack on a Segment

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
    int n, s;
    cin >> n >> s;
    vector<int> wt(n), cost(n);
    for (auto &x : wt) cin >> x;
    for (auto &x : cost) cin >> x;
    ll ans = 0, cur_wt = 0, cur_cost = 0;
    for (int l = 0, r = 0; r < n; r++) {
        cur_wt += wt[r];
        cur_cost += cost[r];
        while (l <= r && s < cur_wt) {
            cur_wt -= wt[l];
            cur_cost -= cost[l];
            l++;
        }
        ans = max(ans, cur_cost);
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