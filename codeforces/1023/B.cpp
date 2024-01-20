/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Pair of Toys

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
    ll n, k;
    cin >> n >> k;
    ll ways = (k - 1) / 2;
    ll min_money = (k / 2) + 1;
    ll ans = min(ways, max(0LL, n - min_money + 1));
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