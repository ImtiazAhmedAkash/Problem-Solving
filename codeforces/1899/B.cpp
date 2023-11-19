/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 250 Thousand Tons of TNT

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
    partial_sum(A.begin(), A.end(), A.begin());
    ll ans = 0;
    for (int x = 1; x < n; x++) {
        if (n % x) continue;
        ll maxi = -INF, mini = INF;
        for (int i = x; i <= n; i += x) {
            ll cur = A[i] - A[i - x];
            maxi = max(maxi, cur);
            mini = min(mini, cur);
        }
        ans = max(ans, maxi - mini);
    }
    cout << ans << nl;
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