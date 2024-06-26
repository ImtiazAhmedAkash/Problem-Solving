/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 343

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5;

void solve() {
    ll n;
    cin >> n;

    auto isPalindrome = [&](string s) -> bool {
        string t(s.rbegin(), s.rend());
        return (s == t);
    };

    ll x = cbrt(n + 5);

    for (ll i = x; i > 0; i--) {
        ll cur = i * i * i;
        string s = to_string(cur);
        if (isPalindrome(s) && cur <= n) {
            cout << s << nl;
            return;
        }
    }
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