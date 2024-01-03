/*  In the Name of ALLAH, the most gracious, the most merciful  */

// FizzBuzz Sum Hard

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
    ll n, a, b;
    cin >> n >> a >> b;

    auto sum = [&](ll x) {
        return x * (x + 1) / 2;
    };

    ll l = lcm(a, b);
    ll ans = sum(n) - a * sum(n / a) - b * sum(n / b) + l * sum(n / l);
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