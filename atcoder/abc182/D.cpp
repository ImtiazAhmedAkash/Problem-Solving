/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Wandering

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
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<ll> delta(n + 1), profit(n + 1);
    for (int i = 1; i <= n; i++) {
        delta[i] = delta[i - 1] + A[i];
        profit[i] = max(profit[i - 1], delta[i]);
    }
    ll ans = 0, cur_pos = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, cur_pos + profit[i]);
        cur_pos += delta[i];
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