/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Even Digits

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
    if (n == 1) {
        cout << 0 << nl;
        return;
    }
    string s = "";
    n--;
    while (n > 0) {
        s += to_string(n % 5);
        n /= 5;
    }
    reverse(s.begin(), s.end());
    ll ans = 2 * stoll(s);
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