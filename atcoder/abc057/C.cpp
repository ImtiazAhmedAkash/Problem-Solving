/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Digits in Multiplication

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
    ll n;
    cin >> n;

    auto fun = [&](ll a, ll b) {
        string x = to_string(a);
        string y = to_string(b);
        return (int)max(x.size(), y.size());
    };

    int ans = inf;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans = min(ans, fun(i, n / i));
        }
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